/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/23 20:01:10 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
//static int nbcompare = 0;
//int len = *(jacob.end() - 2) + *(jacob.end() - 1) - 1;
#include <cmath>

void loser_from_winner(vector &array, vector &loser, unsigned int packetsize)
{
	int i = 1;

	for (vector::iterator it = array.begin(); it + 1 < array.end(); it += packetsize)
	{
		loser_packet(array, packetsize, i, loser);
		i++;
	}

	if (array.size() % packetsize != 0)
		loser_packet(array, packetsize, i - 1, loser);
}

void	insert_losers(vector &array, vector &loser, unsigned int packetsize)
{
	vector jacob = jacob_sequence(loser, packetsize);

	insert_packet_at_index(array, packetsize, 1, loser, 1);

	std::cout << DBLUE "w first packg inserted array = ";
	print_vector(array);
	std::cout << DBLUE "w first packg inserted loser = ";
	print_vector(loser);
	std::cout << RESET;

	unsigned int jacob_index = 1;
	int index = 0;
	int current;
	while (jacob_index <= jacob.size() - 1)
	{
		index = jacob.at(jacob_index);
		current = packet_value(loser, packetsize, index);
		unsigned int where = binary_search_packets(array, packetsize, current);
	
		insert_packet_at_index(array, packetsize, where, loser, jacob.at(jacob_index));
	
		++index;
		--jacob.at(jacob_index);
		if (jacob.at(jacob_index) <= jacob.at(jacob_index - 1))
			++jacob_index;
	}
	if (loser.size() % packetsize != 0)
	{
		current = packet_value(loser, packetsize, index + 1);
		unsigned int where = binary_search_packets(array, packetsize, current);
		insert_packet_at_index(array, packetsize, where, loser, packets_nb(loser, packetsize) + 1);
	}
	std::cout << DBLUE "array = ";
	print_vector(array);
	std::cout << DBLUE "loser = ";
	print_vector(loser);
	std::cout << RESET;
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

void algo(vector &array)
{

	loser_winner(array, 1);
	//packet_division(array, loser);
	print_vector(array);

}
