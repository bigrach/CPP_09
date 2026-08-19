/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:43:44 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/19 18:02:51 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits.h>

// using vector and list
// algo is on page 192 of the document provided (180 in-book)
int	main(int argc, char **argv)
{
	vector	array;
	std::list<int>		list;

	try {
		check_arguments(argc, argv, array, list);
		//car_rock_algo(vector, list);
	} 
	catch(const char *e) {
		std::cout << RED "Error: " << e << RESET << std::endl;
		return 1;
	}
	test(array);
	
	return 0;
}

int	check_arguments(int argc, char **argv, vector &array, std::list<int> &list)
{
	if (std::string (argv[0]) != "./PmergeMe")
		throw "Invalid program name, should be 'PmergeMe'.";

	for (int i = 1; i < argc; ++i)
	{
		//std::cout << "arg = '" << argv[i] << "'" << std::endl;
		char *leftovers;
		long number = std::strtol(argv[i], &leftovers, 10);
		if (number > INT_MAX || number < 0)
			throw "invalid number in arguments";
		if (leftovers != NULL && leftovers[0] != '\0')
		{
			std::cout << "'" << leftovers << "'" << std::endl;
			std::cout << "'" << leftovers << "'" << std::endl;
			throw "shit in argument";
		}
		array.push_back(number);
		list.push_back(number);
	}
	if (array.size() <= 1)
		throw "nothing to sort";
	std::cout << std::setw(10) << PURPLE "Before: " << std::flush;
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << ' ' << std::flush;
	std::cout << RESET << std::endl;
	return 0;
}
