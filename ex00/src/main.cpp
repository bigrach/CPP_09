/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:43:44 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/15 15:19:08 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// using the map container
int	main(int argc, char **argv)
{
	std::ifstream database;
	std::ifstream inputfile;

	if (check_files(argc, argv, database, inputfile))
	{
		std::cerr << RESET << std::flush;
		return 1;
	}
	try {
		thisMap data = make_map(database);
		study_input(data, inputfile);
	} 
	catch(const char *e) {
		std::cout << RED "Error in database: " << e << RESET << std::endl;
		return 1;
	}
	return 0;
}

int	check_files(int argc, char **argv, std::ifstream &database, std::ifstream &input)
{
	if (std::string(argv[0]) != "./btc")
	{
		std::cerr << RED "Program name is invalid. Should be 'btc'." << std::endl;
		return 1;
	}

	if (argc != 2)
	{
		std::cerr << RED "Invalid number of arguments." << std::endl;
		return 1;
	}

	database.open("data.csv");
	if (!database.is_open())
	{
		perror(RED "Issue with database file");
		return 1;
	}

	input.open(argv[1]);
	if (!input.is_open())
	{
		std::cerr << RED << std::flush;
		perror(argv[1]);
		return 1;
	}
	return 0;
}