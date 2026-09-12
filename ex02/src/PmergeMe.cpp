/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/12 17:09:34 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <algorithm>
#include <sys/time.h>

void separate_losers_from_winners(vector &array, vector &loser, unsigned int packetsize)
{
	int i = 1;

	for (vector::iterator it = array.begin(); it < array.end(); it += packetsize)
	{
		loser_packet(array, packetsize, i, loser);
		i++;
	}
}

void	loser_insertion(vector &array, vector &loser, unsigned int packetsize)
{
	vector	jacob = jacob_sequence(loser, packetsize);
	vector	jacobref(jacob);
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
		if (jacob.at(jacob_index) <= jacobref.at(jacob_index - 1))
			++jacob_index;
		if ((unsigned int)jacobref.at(jacob_index - 1) >= how_many_packets(loser, packetsize))
			break ;
	}
}

void	sort_by_packets(vector &array, unsigned int packetsize)
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
	
	vector loser;
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

void rockcaralgo(int argc, char **argv, vector &array)
{
	for (int i = 1; i < argc; ++i)
	{
		char *leftovers;
		long number = std::strtol(argv[i], &leftovers, 10);
		array.push_back(number);
	}
	sort_by_packets(array, 1);
}

void displayInfo(vector array, std::string what, int howManyTotal, int nbcompareW, size_t period)
{
	for (vector::iterator it = array.begin(); it != array.end(); ++it)
		std::cout << *it << ' ' << std::flush;
	std::cout << std::endl; 
	std::cout << "Time to process a range of " << howManyTotal << " elements with " << what << ": " << period << " us" << std::endl;
	std::cout << "Values in vector are " << is_sorted_vector(array) << std::endl;
	std::cout << "Number of comparisons for vector: " << nbcompareW << " maximum allowed by algo = " << max_nb_comparisons(array.size()) << std::endl;
	std::cout << "How many number in vector: " << array.size() << " how many in arguments: " << howManyTotal << std::endl;

}

/**
 * @brief Timing the algo, and printing the necessary information. 
 */
void algo(int argc, char **argv)
{
	// vector part
	vector first;
	unsigned int nbcompareVec = 0;

	struct timeval startVec, endVec;
	gettimeofday(&startVec, NULL);
	double startV = startVec.tv_sec * 1000000 + startVec.tv_usec;

	rockcaralgo(argc, argv, first);

	gettimeofday(&endVec, NULL);
	double periodV = (endVec.tv_sec * 1000000 + endVec.tv_usec) - startV;
	nbcompareVec = nbcompare;

	nbcompare = 0;
	// deque part
	/*
	deque second;
	struct timeval startDeque, endDeque;
	gettimeofday(&startVec, NULL);
	double startD = startDeque.tv_sec * 1000000 + startDeque.tv_usec;

	//rockcaralgo(argc, argv, second);

	gettimeofday(&endDeque, NULL);
	double periodD = (endDeque.tv_sec * 1000000 + endDeque.tv_usec) - startD;
*/
	std::cout << "After : " << std::flush;
	displayInfo(first, "std::vector", argc - 1, nbcompareVec, periodV);
}
