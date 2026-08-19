/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/19 18:39:42 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
//static int nbcompare = 0;

void	print_vector(std::vector<int> &vector)
{
	std::cout << std::setw(10) << PURPLE "After : " << ' ' << std::flush;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << *it << ' ' << std::flush;
	std::cout << RESET << std::endl;
}

bool	is_sorted_vector(std::vector<int> &array)
{
	for (vector::iterator it = array.begin(); it + 1 != array.end(); ++it)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

unsigned int packets_nb(vector &array, unsigned int packetsize)
{
	return array.size() / packetsize;
}

int actual_index(unsigned int packetsize, unsigned int groupindex)
{
	if ((groupindex - 1) * packetsize < 0)
		return 0;
	return (groupindex - 1) * packetsize;
}

int packet_value(vector &array, unsigned int packetsize, unsigned int groupindex)
{
	return array.at(actual_index(packetsize, groupindex));
}

void loser_packet(vector &array, unsigned int packetsize, unsigned int groupindex, vector &destination)
{
	vector::iterator target;
	target = array.begin() + actual_index(packetsize, groupindex);
	while (packetsize)
	{
		destination.push_back(*target);
		array.erase(target);
		--packetsize;
	}
}
// fancy swap - takes the first package and swaps it with the next one
void merge(vector &array, unsigned int packetsize, unsigned int groupindex)
{
	vector::iterator target;
	vector temp;

	loser_packet(array, packetsize, groupindex, temp);
	print_vector(temp);
	target = array.begin() + actual_index(packetsize, groupindex + 1);
	array.insert(target, temp.begin(), temp.end());
}

bool binary_search(vector &array, int searchingfor)
{
	int start = 0;
	int end = array.size();
	int midpoint = array.size() / 2;

	while (start < end)
	{
		if (searchingfor > array.at(midpoint))
			start = midpoint + 1;
		else
			end = midpoint - 1;
		midpoint = (end + start) / 2;
	}
	if ((size_t)start < array.size() && array[start] == searchingfor)
	{
		std::cout << "found" << std::endl;
		return true;
	}
	std::cout << "not found" << std::endl;
	return false;
}

bool binary_insert(vector &array, int nifty)
{
	int start = 0;
	int end = array.size();
	int midpoint = array.size() / 2;

	while (start < end)
	{
		if (nifty > array.at(midpoint))
			start = midpoint + 1;
		else
			end = midpoint - 1;
		midpoint = (end + start) / 2;
	}
	if (end < 0)
		end = 0;
	vector::iterator target = array.begin() + end;
	array.insert(target, nifty);
	return false;
}



void test(vector &array)
{
	std::cout << PURPLE "array size = " RESET << array.size() << std::endl;
	if (is_sorted_vector(array))
		std::cout << "array is sorted" << std::endl;
	print_vector(array);
	std::cout << PURPLE "binary search" RESET << std::endl;
	std::cout << "binary search - looking for 1" << std::endl;
	binary_search(array, 1);
	std::cout << "binary search - looking for 5" << std::endl;
	binary_search(array, 5);
	std::cout << "binary search - looking for 11" << std::endl;
	binary_search(array, 11);
	
	std::cout << PURPLE "binary insert" RESET << std::endl;
	std::cout << "binary insert - looking for 5" << std::endl;
	binary_insert(array, 5);
	print_vector(array);
	std::cout << "binary insert - looking for 1" << std::endl;
	binary_insert(array, 1);
	print_vector(array);
	std::cout << "binary insert - looking for 11" << std::endl;
	binary_insert(array, 11);
	print_vector(array);
	/*
	std::cout << PURPLE "array size = " RESET << array.size() << std::endl;
	if (is_sorted_vector(array))
		std::cout << "array is sorted" << std::endl;

	std::cout << PURPLE "testing counting packets nb" RESET << std::endl;
	std::cout << "packetsize = 1, packetnb = " << packets_nb(array, 1) << std::endl;
	std::cout << "packetsize = 5, packetnb = " << packets_nb(array, 5) << std::endl;

	std::cout << PURPLE "testing actual index" RESET << std::endl;
	std::cout << "packetsize = 1, groupindex = 5, actual index = " << actual_index(1, 5) << std::endl;
	std::cout << "packetsize = 3, groupindex = 2, actual index = " << actual_index(3, 2) << std::endl;

	std::cout << PURPLE "testing packet value" RESET << std::endl;
	std::cout << "packetsize = 1, groupindex = 5, packet value = " << packet_value(array, 1, 5) << std::endl;
	std::cout << "packetsize = 3, groupindex = 2, packet value  = " << packet_value(array, 3, 2) << std::endl;

	std::cout << PURPLE "testing loser package" RESET << std::endl;
	vector destination;
	std::cout << "packetsize = 1, groupindex = 5" << std::endl;
	print_vector(array);
	loser_packet(array, 1, 5, destination);
	print_vector(array);
	print_vector(destination);

	std::cout << PURPLE "testing merge" RESET << std::endl;
	std::cout << "packetsize = 1, groupindex = 4" << std::endl;
	print_vector(array);
	merge(array, 1, 4);
	print_vector(array);
	std::cout << "packetsize = 2, groupindex = 3" << std::endl;
	print_vector(array);
	merge(array, 2, 3);
	print_vector(array);
	*/

}

/*
std::vector<int>	jacobSequence(std::vector<int> &vector)
{
	int newJacob = 0;
	std::vector<int>	jacob;


	jacob.push_back(3);
	if (5 > vector.size())
		return jacob;
	jacob.push_back(5);
	while (1)
	{
		std::vector<int>::iterator n1 = jacob.end() - 1;
		std::vector<int>::iterator n2 = jacob.end() - 2;
		newJacob = *n1 + 2 * *n2;
		if (newJacob > vector.size())
			return jacob;
		jacob.push_back(newJacob);
	}
	return jacob;
}


void big_and_small(int packetsize, std::vector<int> &vector)
{
	if (packetsize == vector.size());
		return ;
	for (std::vector<int>::iterator it = vector.begin(); it + packetsize < vector.end(); it + packetsize)
	{
		if (*it > *(it + packetsize))
			ft_swap(it, it + 1);
		++nbcompare;
	}
	big_and_small(packetsize * 2, vector);
}


int	sort_vector(std::vector<int> &vector)
{

	big_and_small(1, vector);
	std::vector<int> sorted = insertion(vector);

}


void	car_rock_algo(std::vector<int> &vector, std::list<int> &list)
{
	//std::time_t startvector = std::time(nullptr);
	sort_vector(vector);
	//std::time_t timevector = startvector - std::time(nullptr);
	//int comparevector = nbcompare;

	nbcompare = 0;
	std::time_t startList = std::time(nullptr);
	sort_list(list);
	std::time_t timeList = startList - std::time(nullptr);

	if (check_vector(vector))
		throw "vector is not sorted";
	if (check_list(list))
		throw "list is not sorted";
	print_vector(vector);

	std::cout << std::setw(40) << "Time to process a range of " << vector.size() << " elements with std::vector : " << timevector << " us" << std::endl;
	std::cout << std::setw(40) << "Time to process a range of " << list.size() << " elements with std::list : " << timeList << " us" << std::endl;
	std::cout << "Number of comparisons with std::vector = " << comparevector << std::endl;
	std::cout << "Number of comparisons with std::list = " << nbcompare << std::endl;

}
*/