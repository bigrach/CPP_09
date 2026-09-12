/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:00:45 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/12 15:38:12 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned int	how_many_packets(vector &array, unsigned int packetsize)
{
	return array.size() / packetsize;
}

unsigned int	actual_index(unsigned int packetsize, unsigned int packetindex)
{
	return (packetindex - 1) * packetsize;
}

int	packet_value(vector &array, unsigned int packetsize, unsigned int packetindex)
{
	return array.at(actual_index(packetsize, packetindex) + packetsize - 1);
}

/**
	@brief Move packetindex's packet from array to loser array

	@param array The array containing all the winners
	@param packetsize Current size of packets
	@param packetindex Which group we want to move 
	@param destination The loser array
	@param target Iterator pointing to where the group is in the array
 */
void	loser_packet(vector &array, unsigned int packetsize, unsigned int packetindex, vector &destination)
{
	vector::iterator	target = array.begin() + actual_index(packetsize, packetindex);
	
	if (target + packetsize > array.end())
		return ;
	
	while (packetsize)
	{
		destination.push_back(*target);
		array.erase(target);
		--packetsize;
	}
}

/**
	@brief Fancy swap - takes a packetindex's packet and swaps it with the next one
 */
void	merge(vector &array, unsigned int packetsize, unsigned int packetindex)
{
	vector::iterator	target;
	vector				temp;

	int	firstvalue = packet_value(array, packetsize, packetindex);
	int	secondvalue = packet_value(array, packetsize, packetindex + 1);

	if (firstvalue > secondvalue)
		loser_packet(array, packetsize, packetindex, temp);
	++nbcompare;
	target = array.begin() + actual_index(packetsize, packetindex + 1);

	array.insert(target, temp.begin(), temp.end());
}