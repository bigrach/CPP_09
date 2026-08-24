/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/24 18:11:16 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//int len = *(jacob.end() - 2) + *(jacob.end() - 1) - 1;
#include <cmath>
#include <algorithm>

/*
{
	size_t nb_group = ;
	for (size_t i = 1; i <= nb_group; i += 2)
		// move group i
}*/
// separate losers from winners
void loser_from_winner(vector &array, vector &loser, unsigned int packetsize)
{
	int i = 1;

	for (vector::iterator it = array.begin(); it < array.end(); it += packetsize)
	{
		loser_packet(array, packetsize, i, loser);
		i++;
	}
//	std::cout << "total = " << array.size() + loser.size() << std::endl;
}

void	insert_losers(vector &array, vector &loser, unsigned int packetsize)
{
	vector	jacob = jacob_sequence(loser, packetsize);
	vector	jacobref(jacob);
/*
	std::cout << "packetsize = " << packetsize << std::endl;
	std::cout << DBLUE "array = ";
	print_vector(array);
	std::cout << DBLUE "loser = ";
	print_vector(loser);
	std::cout << RESET;
*/
	insert_packet_at_index(array, packetsize, 1, loser, 1);
/*
	std::cout << DBLUE "array (after first insertion)= ";
	print_vector(array);
	std::cout << DBLUE "loser (after first insertion)= ";
	print_vector(loser);
	std::cout << DBLUE << "loser packet nb = " << packets_nb(loser, packetsize) << " packetsize = " << packetsize << std::endl;
	std::cout << RESET;
*/

	unsigned int jacob_index = 1;
	unsigned int index = 0;
	int current;
	//unsigned int packetnbloser = packets_nb(loser, packetsize);
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
	/*
	if (packetnbloser % 2 != 0)
	{
		current = packet_value(loser, packetsize, packets_nb(loser, packetsize));
		unsigned int where = binary_search_packets(array, packetsize, current, packets_nb(array, packetsize));
		insert_packet_at_index(array, packetsize, where, loser, packets_nb(loser, packetsize));
	}*/
	/*
	std::cout << DBLUE "array size = " << array.size() << " array = ";
	print_vector(array);
	std::cout << DBLUE "loser = ";
	print_vector(loser);
	std::cout << RESET;*/
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
	//std::cout << "array size = " << array.size() << " after merge = ";
	//print_vector(array);

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



void algo(vector &array)
{
	vector result(array);
	std::cout << array.size() << std::endl;
	loser_winner(array, 1);
	if (is_sorted_vector(array))
		std::cout << "amen" << std::endl;
	/*std::cout << PURPLE << "array size = " << array.size() << " final array = "<< std::endl;
	print_vector(array);
	std::sort (result.begin(), result.end());
	std::cout << PURPLE << "result size = " << result.size() << "(sorted by the machine) = "<< std::endl;
	print_vector(result);*/
	std::cout << "compare nb = " << nbcompare << " what it should be = " << howmany(array.size()) << std::endl;
}
