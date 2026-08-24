/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:24:28 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/24 18:35:01 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <cstdlib>

// COLORS
 #define RESET "\x1b[0m"
 #define RED "\x1B[1;91m"
 #define DBLUE "\x1b[1;36m"
 #define PURPLE "\x1B[1;35m"
 #define GRAY "\x1b[2;37m"
 #define GREEN "\e[1;32m"

extern int nbcompare;
typedef std::vector<unsigned int> vector;

// real business
void	algo(vector &array);

// VECTOR BASICS
void	print_vector(vector &vector);
bool	is_sorted_vector(vector &array);

// HELPER FUNCTIONS
unsigned int	packets_nb(vector &array, unsigned int packetsize);
unsigned int	actual_index(unsigned int packetsize, unsigned int groupindex);
int				packet_value(vector &array, unsigned int packetsize, unsigned int groupindex);
void			loser_packet(vector &array, unsigned int packetsize, unsigned int groupindex, vector &destination);
void			merge(vector &array, unsigned int packetsize, unsigned int groupindex);
void			insert_packet_at_index(vector &array, int packetsize, unsigned int destgroupindex, vector &loser, unsigned int losergroupindex);
void			packet_binary_insert(vector &array, vector &jacob, int packetsize, vector &loser, unsigned int losergroupindex);

// BINARY TRIES
bool	binary_search(vector &array, int searchingfor);
bool	binary_insert(vector &array, int number);

// FUNCTIONS
int		check_arguments(int argc, char **argv, vector &array, std::list<int> &list);

// PACKET INSERT
void	insert_packet_at_index(vector &array, unsigned int packetsize, unsigned int destgroupindex, vector &loser, unsigned int losergroupindex);
int		binary_search_packets(vector &array, unsigned int packetsize, int searchingfor, int end);
vector	jacob_sequence(vector &array, unsigned int packetsize);


#endif
