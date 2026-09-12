/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:43:44 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/12 19:24:59 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits.h>

int nbcompare = 0;

int	main(int argc, char **argv)
{
	try {
		check_arguments(argc, argv);
		algo(argc, argv);
	} 
	catch(const char *e) {
		std::cout << RED "Error: " << e << RESET << std::endl;
		return 1;
	}
	return 0;
}

int	check_arguments(int argc, char **argv)
{
	if (std::string (argv[0]) != "./PmergeMe")
		throw "Invalid program name, should be 'PmergeMe'.";

	if (argc < 2)
		throw "Nothing to sort";
	
	for (int i = 1; i < argc; ++i)
	{
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
	}

	std::cout << std::setw(10) << PURPLE "Before: " << std::flush;
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << ' ' << std::flush;
	std::cout << RESET << std::endl;
	return 0;
}
