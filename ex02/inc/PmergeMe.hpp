/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:24:28 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/12 16:53:52 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
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
typedef std::deque<unsigned int> deque;


// real business
void	algo(int argc, char **argv);
// VECTOR BASICS
void		print_vector(vector &vector);
std::string	is_sorted_vector(vector &array);

// HELPER FUNCTIONS
unsigned int	how_many_packets(vector &array, unsigned int packetsize);
unsigned int	actual_index(unsigned int packetsize, unsigned int packetindex);
int				packet_value(vector &array, unsigned int packetsize, unsigned int packetindex);
void			loser_packet(vector &array, unsigned int packetsize, unsigned int packetindex, vector &destination);
void			merge(vector &array, unsigned int packetsize, unsigned int packetindex);
void			insert_packet_at_index(vector &array, unsigned int packetsize, unsigned int destpacketindex, vector &loser, unsigned int loserpacketindex);

// FUNCTIONS
int	check_arguments(int argc, char **argv);

// PACKET INSERT
void	insert_packet_at_index(vector &array, unsigned int packetsize, unsigned int destpacketindex, vector &loser, unsigned int loserpacketindex);
int		binary_search_packets(vector &array, unsigned int packetsize, int searchingfor, int end);
vector	jacob_sequence(vector &array, unsigned int packetsize);


#endif
