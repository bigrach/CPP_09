/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/13 13:49:56 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <algorithm>
#include <sys/time.h>

/**
 * ░█░█░▀█▀░▀█▀░█░░░█▀▀
 * ░█░█░░█░░░█░░█░░░▀▀█
 * ░▀▀▀░░▀░░▀▀▀░▀▀▀░▀▀▀
 */

template <typename T>
unsigned int	how_many_packets(T &array, unsigned int packetsize)
{
	return array.size() / packetsize;
}

unsigned int	actual_index(unsigned int packetsize, unsigned int packetindex)
{
	return (packetindex - 1) * packetsize;
}

template <typename T>
int	packet_value(T &array, unsigned int packetsize, unsigned int packetindex)
{
	return array.at(actual_index(packetsize, packetindex) + packetsize - 1);
}

template <typename T>
void	print_vector(T &array)
{
	for (typename T::iterator it = array.begin(); it != array.end(); ++it)
		std::cout << *it << ' ' << std::flush;
	std::cout << RESET << std::endl;
}

template <typename T>
bool	is_sorted_vector(T &array)
{
	for (typename T::iterator it = array.begin(); it + 1 != array.end(); ++it)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

/**
 *
 * ░█▀█░█▀█░█▀▀░█░█░█▀▀░▀█▀░░░▀█▀░█▀█░█▀▀░█▀▀░█▀▄░▀█▀
 * ░█▀▀░█▀█░█░░░█▀▄░█▀▀░░█░░░░░█░░█░█░▀▀█░█▀▀░█▀▄░░█░
 * ░▀░░░▀░▀░▀▀▀░▀░▀░▀▀▀░░▀░░░░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░░▀░
 *
 */

template <typename T>
int	binary_search_packets(T &array, unsigned int packetsize, int searchingfor, int end)
{
	int start = 1;
	int total = how_many_packets(array, packetsize);
	if (end > total)
		end = total;
	int midpoint = (end + start) / 2;
	
	while (start <= end)
	{
		if (searchingfor > packet_value(array, packetsize, midpoint))
			start = midpoint + 1;
		else
			end = midpoint - 1;
		midpoint = (end + start) / 2;
		++nbcompare;
	}
	if (end <= 0)
		end = 1;
	else
		end = ++end;
	return end;
}

template <typename T>
void	insert_packet_at_index(T &array, unsigned int packetsize, unsigned int destpacketindex, T &loser, unsigned int loserpacketindex)
{
	unsigned int index_dest = actual_index(packetsize, destpacketindex);
	if (index_dest > array.size())
		index_dest = array.size();

	unsigned int index_og = actual_index(packetsize, loserpacketindex);
	if (index_og > loser.size())
		index_og = loser.size();


	for (unsigned int i = 0; i < packetsize; ++i)
	{
		typename T::iterator	origin = loser.begin() + index_og;
		typename T::iterator	dest = array.begin() + index_dest;
		if (origin + i >= loser.end())
			return ;
		array.insert(dest + i, *(origin + i));
	}
}

template <typename T>
T	jacob_sequence(T &array, unsigned int packetsize)
{
	T	jacob;
	unsigned int max_size = how_many_packets(array, packetsize);
	if (array.size() % packetsize != 0)
		++max_size;
	jacob.push_back(1);
	unsigned int newJacob = 3;

	while (newJacob <= max_size)
	{
		jacob.push_back(newJacob);
		newJacob = *(jacob.end() - 1) + 2 * *(jacob.end() - 2);
	}
	jacob.push_back(newJacob);
	return jacob;
}

/**
 * ░█▀█░█░░░█▀▀░█▀█░░░█▀▀░▀█▀░▀█▀░█░█
 * ░█▀█░█░░░█░█░█░█░░░█░░░░█░░░█░░░█░
 * ░▀░▀░▀▀▀░▀▀▀░▀▀▀░░░▀▀▀░▀▀▀░░▀░░░▀░
 */

/**
	@brief Move packetindex's packet from array to loser array

	@param array The array containing all the winners
	@param packetsize Current size of packets
	@param packetindex Which group we want to move 
	@param destination The loser array
	@param target Iterator pointing to where the group is in the array
 */
template <typename T>
void	loser_packet(T &array, unsigned int packetsize, unsigned int packetindex, T &destination)
{
	typename T::iterator	target = array.begin() + actual_index(packetsize, packetindex);
	
	if (target + packetsize > array.end())
		return ;
	
	while (packetsize)
	{
		destination.push_back(*target);
		target = array.erase(target);
		--packetsize;
	}
}

/**
	@brief Fancy swap - takes a packetindex's packet and swaps it with the next one
 */
template <typename T>
void	merge(T &array, unsigned int packetsize, unsigned int packetindex)
{
	typename T::iterator	target;
	T				temp;

	int	firstvalue = packet_value(array, packetsize, packetindex);
	int	secondvalue = packet_value(array, packetsize, packetindex + 1);

	if (firstvalue > secondvalue)
		loser_packet(array, packetsize, packetindex, temp);
	++nbcompare;
	target = array.begin() + actual_index(packetsize, packetindex + 1);

	array.insert(target, temp.begin(), temp.end());
}

template <typename T>
void separate_losers_from_winners(T &array, T &loser, unsigned int packetsize)
{
	int i = 1;

	for (typename T::iterator it = array.begin(); it < array.end(); it += packetsize)
	{
		loser_packet(array, packetsize, i, loser);
		i++;
	}
}

template <typename T>
void	loser_insertion(T &array, T &loser, unsigned int packetsize)
{
	T	jacob = jacob_sequence(loser, packetsize);
	T	jacobref(jacob);
	int	current;

	insert_packet_at_index(array, packetsize, 1, loser, 1);

	unsigned int	jacob_index = 1;
	unsigned int	index = 0;

	while (jacob_index <= jacob.size() - 1)
	{
		if ((unsigned int)jacob.at(jacob_index) > how_many_packets(loser, packetsize))
			jacob.at(jacob_index) = how_many_packets(loser, packetsize);

		index = jacob.at(jacob_index);
		current = packet_value(loser, packetsize, index);

		int end = jacobref.at(jacob_index - 1) + jacobref.at(jacob_index) - 1;
		unsigned int where = binary_search_packets(array, packetsize, current, end);

		insert_packet_at_index(array, packetsize, where, loser, jacob.at(jacob_index));

		--jacob.at(jacob_index);
		if (jacob[jacob_index] <= jacobref.at(jacob_index - 1))
			++jacob_index;
		if ((unsigned int)jacobref.at(jacob_index - 1) >= how_many_packets(loser, packetsize))
			break ;
	}
}

template <typename T>
void	sort_by_packets(T &array, unsigned int packetsize)
{
	unsigned int	totalpackets = how_many_packets(array, packetsize);
	unsigned int	packetindex = 1;

	if (totalpackets < 2)
		return ;

	while (packetindex <= totalpackets - 1)
	{
		merge(array, packetsize, packetindex);
		packetindex += 2;
	}

	sort_by_packets(array, 2 * packetsize);
	if (how_many_packets(array, packetsize) < 3)
		return ;

	T loser;
	separate_losers_from_winners(array, loser, packetsize);
	loser_insertion(array, loser, packetsize);
}

int max_nb_comparisons(int nb)
{
	int maxComparison = 0;

	for (int i = 1; i <= nb; ++i)
	{
		double log2 = std::log(0.75 * i) / std::log(2);
		maxComparison += std::ceil(log2);
	}
	return maxComparison;
}

template <typename T>
double rockcaralgo(int argc, char **argv, T &array)
{
	struct timeval startVec, endVec;
	gettimeofday(&startVec, NULL);
	double startV = startVec.tv_sec * 1000000 + startVec.tv_usec;

	for (int i = 1; i < argc; ++i)
	{
		char *leftovers;
		long number = std::strtol(argv[i], &leftovers, 10);
		array.push_back(number);
	}
	sort_by_packets(array, 1);
	gettimeofday(&endVec, NULL);
	return (endVec.tv_sec * 1000000 + endVec.tv_usec) - startV;
}

template <typename T>
void displayInfo(T &array, std::string what, unsigned int howManyTotal, int nbcompareW, size_t period)
{
	std::cout << PURPLE "for " << what << ' ' << RESET << std::endl;
	std::cout << BLUE "Time to process a range of " << howManyTotal << " elements with std::" << what << ": " << period << " us" << std::endl;
	std::cout << BLUE "Number of comparisons for " << what << " = " << nbcompareW << std::endl;
	if (array.size() ==  howManyTotal)
		std::cout << GREEN << "There is the right amount of numbers in the array at the end." << RESET << std::endl;
	else
		std::cout << RED << "There is NOT the right amount of numbers in the array at the end." << RESET << std::endl;
	if (is_sorted_vector(array))
		std::cout << GREEN << "The " << what << " array is sorted" << RESET << std::endl;
	else
		std::cout << RED << "The " << what << " array is not sorted" << RESET << std::endl;	
	std::cout << "Maximum number of comparisons allowed by algo = " << max_nb_comparisons(array.size()) << RESET << std::endl;

}

/**
 * ░█▀█░█░░░█▀▀░█▀█░░░▀█▀░▀█▀░█▀▀░█▄█
 * ░█▀█░█░░░█░█░█░█░░░░█░░░█░░█▀▀░█░█
 * ░▀░▀░▀▀▀░▀▀▀░▀▀▀░░░░▀░░▀▀▀░▀▀▀░▀░▀
 */

/**
 * @brief Timing the algo, and printing the necessary information.
 */
void algo(int argc, char **argv)
{
	// vector part
	vector first;
	unsigned int nbcompareVec = 0;

	double periodV = rockcaralgo(argc, argv, first);
	nbcompareVec = nbcompare;

	// deque part
	deque second;
	nbcompare = 0;
	double periodD = rockcaralgo(argc, argv, second);

	std::cout << DBLUE "After : " << std::flush;
	for (vector::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << *it << ' ' << std::flush;

	std::cout << RESET << std::endl;
	displayInfo(first, "vector", argc - 1, nbcompareVec, periodV);
	
	for (deque::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << ' ' << std::flush;
	std::cout << RESET << std::endl;
	displayInfo(second, "deque", argc - 1, nbcompareVec, periodD);
}