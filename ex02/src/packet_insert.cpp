/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:00:29 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/24 18:14:36 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	binary_search_packets(vector &array, unsigned int packetsize, int searchingfor, int end)
{
	int start = 1;
	int total = packets_nb(array, packetsize);
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

void insert_packet_at_index(vector &array, unsigned int packetsize, unsigned int destgroupindex, vector &loser, unsigned int losergroupindex)
{
	unsigned int index_dest = actual_index(packetsize, destgroupindex);
	if (index_dest > array.size())
		index_dest = array.size();

	unsigned int index_og = actual_index(packetsize, losergroupindex);
	if (index_og > loser.size())
		index_og = loser.size();

	vector::iterator origin = loser.begin() + index_og;
	vector::iterator dest = array.begin() + index_dest;
	for (unsigned int i = 0; i < packetsize; ++i)
	{
		if (origin + i >= loser.end())
			return ;
		array.insert(dest + i, *(origin + i));
	}
}

vector jacob_sequence(vector &array, unsigned int packetsize)
{
	vector	jacob;
	unsigned int max_size = packets_nb(array, packetsize);
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

