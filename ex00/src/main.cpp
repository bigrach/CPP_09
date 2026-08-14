/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre.42angouleme@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:43:44 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/14 14:47:32 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"
#include <vector>
#include <iterator>
#include <fstream>
#include <map>

int check_files(int argc, char **argv, std::ifstream *database, std::ifstream *input)
{
	(*database).open("data.csv");
	if (!(*database).is_open())
	{
		perror("Issue with database file: ");
		return 1;
	}

	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}

	(*input).open(argv[1]);
	if (!(*input).is_open())
	{
		perror(argv[1]);
		return 1;
	}
	return 0;
}

int check_date_validity(std::string input)
{
	int year = std::strtol(input.c_str(), NULL, 10);
	int month = std::strtol(input.c_str(), NULL, 10);
	int day = std::strtol(input.c_str(), NULL, 10);

	switch (month)
	{
		case 4: case 6: case 9: case 11:
			if (day > 30)
				return 1;
			return 0;

		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day > 31)
				return 1;
			return 0;

		case 2:
			if (year % 4 == 0 && day > 29)
				return 1;
			else if (day > 28)
				return 1;
			return 0;

		default:
			return 1;
	}
}

// throw errors instead of returns ?
int decent_date(std::string input, int case)
{
	std::string dateFormat = "xxxx-xx-xx";

	for (int i = 0; i < 10; ++i)
	{
		if (dateFormat[i] == 'x' && !isdigit(input[i]))
			return 1;
		if (dateFormat[i] == '-' && input[i] != '-')
			return 1;
	}

	if (check_date_validity(input))
		return 1;

	return 0;
}

std::map<std::string, int> get_data(std::ifstream &database)
{
	std::string buffer;
	std::map<std::string, int> data;

	while (!database.eof())
	{
		char *leftovers = NULL;
		std::getline(database, buffer);
		if (buffer.size() < 13) // empty lines?
			throw BadLine;
		if (decent_date(buffer))
			throw InvalidDate;
		long value = strtol(&buffer[12], &leftovers, 10);
		if (leftovers != NULL)
			throw ShitInLine;
		else if (value > 1000)
			throw BadValue;
		data[buffer.substr(0, 10)] = value;
	}
}




int	main(int argc, char **argv)
{
	std::ifstream database;
	std::ifstream wanted;
	if (check_files(argc, argv, &database, &wanted))
		return 1;
	try {
		std::map<std::string, int> data = get_data(database);
		std::map<std::string, int> input = checkwhatwewant();
		makeshitup(data, input);
	} 
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	
}
