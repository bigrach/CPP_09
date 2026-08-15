/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre.42angouleme@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:43:44 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/15 22:32:22 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits.h>

// using deque and list
int	main(int argc, char **argv)
{
	std::deque<int>	deque;
	std::list<int>		list;

	try {
		check_arguments(argc, argv, deque, list);
		car_rock_algo(deque, list);
	} 
	catch(const char *e) {
		std::cout << RED "Error: " << e << RESET << std::endl;
		return 1;
	}
	return 0;
}

int	check_arguments(int argc, char **argv, std::deque<int> &deque, std::list<int> &list)
{
	if (argc != 2)
		throw "Invalid number of arguments. Put the entire operation in quotes.";
	if (std::string (argv[0]) != "./RPN")
		throw "Invalid program name, should be 'RPN'.";
	for (int i = 1; i < argc; ++i)
	{
		char *leftovers;
		long number = std::strtol(argv[i], &leftovers, 10);
		if (number > INT_MAX || number < 0)
			throw "invalid number in arguments";
		if (leftovers)
			throw "shit in argument";
		deque.push_back(number);
		list.push_back(number);
	}
	std::cout << std::setw(10) << PURPLE "Before: " << std::flush;
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << ' ' << std::flush;
	std::cout << RESET << std::endl;
	return 0;
}