/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/06 16:06:41 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <algorithm>
#include <sys/time.h>

void loser_from_winner(vector &array, vector &loser, unsigned int packetsize)
{
	int i = 1;

	for (vector::iterator it = array.begin(); it < array.end(); it += packetsize)
	{
		loser_packet(array, packetsize, i, loser);
		i++;
	}
}

void	insert_losers(vector &array, vector &loser, unsigned int packetsize)
{
	vector	jacob = jacob_sequence(loser, packetsize);
	vector	jacobref(jacob);
	int	current;

	insert_packet_at_index(array, packetsize, 1, loser, 1);

	unsigned int	jacob_index = 1;
	unsigned int	index = 0;

	while (jacob_index <= jacob.size() - 1)
	{
		if ((unsigned int)jacob.at(jacob_index) > packets_nb(loser, packetsize))
			jacob.at(jacob_index) = packets_nb(loser, packetsize);
		index = jacob.at(jacob_index);
		current = packet_value(loser, packetsize, index);
		int end = jacobref.at(jacob_index - 1) + jacobref.at(jacob_index) - 1;
		unsigned int where = binary_search_packets(array, packetsize, current, end);

		insert_packet_at_index(array, packetsize, where, loser, jacob.at(jacob_index));

		--jacob.at(jacob_index);
		if (jacob.at(jacob_index) <= jacobref.at(jacob_index - 1))
			++jacob_index;
		if ((unsigned int)jacobref.at(jacob_index - 1) >= packets_nb(loser, packetsize))
			break ;
	}
}

void	loser_winner(vector &array, unsigned int packetsize)
{
	unsigned int	totalpackets = packets_nb(array, packetsize);
	unsigned int	groupindex = 1;

	if (totalpackets < 2)
		return ;

	while (groupindex <= totalpackets - 1)
	{
		merge(array, packetsize, groupindex);
		groupindex += 2;
	}

	loser_winner(array, 2 * packetsize);
	if (packets_nb(array, packetsize) < 3)
		return ;
	
	vector loser;
	loser_from_winner(array, loser, packetsize);
	insert_losers(array, loser, packetsize);
}

int howmany(int nb)
{
	int maxComparison = 0;

	for (int i = 1; i <= nb; ++i)
	{
		double log2 = std::log(0.75 * i) / std::log(2);
		maxComparison += std::ceil(log2);
	}
	return maxComparison;
}

// need to fill array here
void algo(int argc, char **argv)
{
	vector array;

	struct timeval startVec, endVec;
	gettimeofday(&startVec, NULL);
	double start = startVec.tv_sec * 1000000 + startVec.tv_usec;

	for (int i = 1; i < argc; ++i)
	{
		char *leftovers;
		long number = std::strtol(argv[i], &leftovers, 10);
		array.push_back(number);
	}

	loser_winner(array, 1);
	gettimeofday(&endVec, NULL);
	double period = (endVec.tv_sec * 1000000 + endVec.tv_usec) - start;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << period << " us" << std::endl;
	
	if (is_sorted_vector(array))
		std::cout << RED "amen" RESET << std::endl;

	std::cout << "compare nb = " << nbcompare << " what it should be = " << howmany(array.size()) << std::endl;
}
