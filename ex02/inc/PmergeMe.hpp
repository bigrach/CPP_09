/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:24:28 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/12 19:58:39 by rlebigre         ###   ########.fr       */
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
 #define BLUE "\x1B[1;96m"
 #define BROWN "\e[1;33m"

extern int nbcompare;
typedef std::vector<unsigned int> vector;
typedef std::deque<unsigned int> deque;


// real business
void	algo(int argc, char **argv);
int		check_arguments(int argc, char **argv);

#include "PmergeMe.tpp"

#endif
