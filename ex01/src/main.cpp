/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre.42angouleme@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:43:44 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/15 20:41:14 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// using stack container
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "Invalid number of arguments. Put the entire operation in quotes." RESET << std::endl;
		return 1;
	}

	try {
		int	value = process_line(argv[1]);
		std::cout << DBLUE << value << RESET << std::endl;
	} 
	catch(const char *e) {
		std::cout << RED "Error: " << e << RESET << std::endl;
		return 1;
	}
	return 0;
}
