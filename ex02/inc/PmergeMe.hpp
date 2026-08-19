/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:24:28 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/19 18:01:34 by rlebigre         ###   ########.fr       */
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

typedef std::vector<int> vector;

// FUNCTIONS
bool	is_sorted_vector(std::vector<int> &array);
void	test(vector &array);
int	check_arguments(int argc, char **argv, vector &array, std::list<int> &list);
/*
void	car_rock_algo(std::vector<int> &array, std::list<int> &list);

// CHECKS
int	check_vector(std::vector<int> &array);
int	check_list(std::list<int> &list);
*/
#endif
