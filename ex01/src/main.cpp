/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:43:44 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/15 18:02:53 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	check_arguments(int argc, char **argv)
{
	if (argc != 2)
		throw "Invalid number of arguments. Put the entire operation in quotes.";
	if (std::string(argv[0]) != "./RPN")
		throw "Invalid program name, should be 'RPN'.";
}

// using stack container
int	main(int argc, char **argv)
{
	try {
		check_arguments(argc, argv);
		if (std::string(argv[1]).empty())
			return 0;
		long value = process_line(argv[1]);
		std::cout << DBLUE << value << RESET << std::endl;
	} 
	catch(const char *e) {
		std::cout << RED "Error: " << e << RESET << std::endl;
		return 1;
	}
	return 0;
}