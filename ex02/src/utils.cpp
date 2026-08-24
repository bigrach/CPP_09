/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:00:45 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/24 18:20:02 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned int	packets_nb(vector &array, unsigned int packetsize)
{
	return array.size() / packetsize;
}

unsigned int	actual_index(unsigned int packetsize, unsigned int groupindex)
{
	return (groupindex - 1) * packetsize;
}

int	packet_value(vector &array, unsigned int packetsize, unsigned int groupindex)
{
	return array.at(actual_index(packetsize, groupindex) + packetsize - 1);
}

void	loser_packet(vector &array, unsigned int packetsize, unsigned int groupindex, vector &destination)
{
	vector::iterator target;
	target = array.begin() + actual_index(packetsize, groupindex);
	
	if (target + packetsize > array.end())
		return ;
	
	while (packetsize)
	{
		destination.push_back(*target);
		array.erase(target);
		--packetsize;
	}
}

// fancy swap - takes the first package and swaps it with the next one
void	merge(vector &array, unsigned int packetsize, unsigned int groupindex)
{
	vector::iterator target;
	vector temp;
	int firstvalue = packet_value(array, packetsize, groupindex);
	int secondvalue = packet_value(array, packetsize, groupindex + 1);

	if (firstvalue > secondvalue)
		loser_packet(array, packetsize, groupindex, temp);
	++nbcompare;
	target = array.begin() + actual_index(packetsize, groupindex + 1);

	array.insert(target, temp.begin(), temp.end());
}