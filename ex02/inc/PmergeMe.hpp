/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:24:28 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/24 17:49:23 by rlebigre         ###   ########.fr       */
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
typedef std::vector<int> vector;

// real business
void algo(vector &array);

// VECTOR BASICS
void	print_vector(std::vector<int> &vector);
bool	is_sorted_vector(std::vector<int> &array);

// TESTS
void	test(vector &array);
void	binaryinsertpackage_tests(void);
void	binaryinsert_tests(void);
void	packetinsertindex_tests(vector &array);
void	binarysearch_tests(vector &array);
void	countingpackets_tests(vector &array);
void	actualindex_tests();
void	packetvalue_tests(vector &array);
void	loserpackage_tests(vector &array);
void	merge_tests(vector &array);

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
//void	car_rock_algo(std::vector<int> &array, std::list<int> &list);

// PACKET INSERT
void	insert_packet_at_index(vector &array, unsigned int packetsize, unsigned int destgroupindex, vector &loser, unsigned int losergroupindex);
int		binary_search_packets(vector &array, unsigned int packetsize, int searchingfor, int end);
vector	jacob_sequence(vector &array, unsigned int packetsize);


#endif
