/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/20 18:28:59 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
//static int nbcompare = 0;

//int len = *(jacob.end() - 2) + *(jacob.end() - 1) - 1;


void insert_packet_at_index(vector &array, int packetsize, unsigned int destgroupindex, vector &loser, unsigned int losergroupindex)
{
	unsigned int index = actual_index(packetsize, destgroupindex);
	if (index > array.size())
		index = array.size();
	
	vector::iterator origin = loser.begin() + actual_index(packetsize, losergroupindex);
	vector::iterator dest = array.begin() + actual_index(packetsize, destgroupindex);
	
	array.insert(dest, origin, origin + packetsize);
}

/** nul */
void package_binary_insert(vector &array, vector &jacob, int packetsize, vector &loser, unsigned int losergroupindex)
{
	(void)jacob;
	
	// working with group index here
	int start = 1;
	int end = 4; // need working jacob
	if ((unsigned int)end > array.size()) 
		end = array.size();
	int midpoint = end / 2;
	int number = packet_value(loser, packetsize, losergroupindex);
	while (start < end)
	{
		if (number > array.at(actual_index(packetsize, midpoint)))
			start = midpoint + 1;
		else
			end = midpoint - 1;
		midpoint = (end + start) / 2;
	}
	if (end < 1)
		end = 1;
	insert_packet_at_index(array, packetsize, end, loser, losergroupindex);
}

//16-18
