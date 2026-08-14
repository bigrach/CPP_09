/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre.42angouleme@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:43:44 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/14 18:38:48 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"
#include <vector>
#include <iterator>
#include <fstream>
#include <map>
#include <cstring>
#include <string>
#include <limits.h>


typedef std::map<std::string,double> thisMap;


int check_files(int argc, char **argv, std::ifstream &database, std::ifstream &input)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}

	database.open("data.csv");
	if (!database.is_open())
	{
		perror("Issue with database file: ");
		return 1;
	}

	input.open(argv[1]);
	if (!input.is_open())
	{
		perror(argv[1]);
		return 1;
	}
	return 0;
}

bool is_leapyear(int year)
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int check_date_validity(std::string input)
{
	int year = std::strtol(input.c_str(), NULL, 10);
	int month = std::strtol(&input[5], NULL, 10);
	int day = std::strtol(&input[8], NULL, 10);

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
			if (is_leapyear(year) && day > 29)
				return 1;
			else if (!is_leapyear(year) && day > 28)
				return 1;
			return 0;

		default:
			return 1;
	}
}

int check_date_validity(std::string input)
{
	const size_t BASE = 10;

	int year = std::strtol(input.c_str(), NULL, BASE);
	int month = std::strtol(&input[5], NULL, BASE);
	int day = std::strtol(&input[8], NULL, BASE);

	switch (month)
	{
		case 4: case 6: case 9: case 11:
			return (day > 30);

		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return (day > 31);

		case 2:
			if (is_leapyear(year))
				return (day > 29);
			return (day > 28);

		default:
			return 1;
	}
}

int decent_date(std::string input)
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

std::map<std::string,double> makeMap(std::ifstream &file)
{
	std::string line;
	thisMap currentMap;
	
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw "y a pas la ligne";
	while (!file.eof())
	{
		std::getline(file, line);
		if (line.length() < 12) // 12 = MINLENGTH
			throw "OUINOUIN"; //TODO: better 
		if (decent_date(line))
			throw "InvalidDate";
		if (line[10] != ',')
			throw "InvalidFormat";
		char *leftovers = NULL;
		double value = strtold(&line[11], &leftovers); // 11 = STARTOFVALUE
		if (*leftovers != '\0')
			throw "ShitInLine";

		currentMap[line.substr(0, 10)] = value; // 10 = END OF DATE
	}
	return currentMap;
}

int	make_calculations(thisMap data, double howmany, std::string &whatday)
{
	thisMap::iterator found = data.lower_bound(whatday);
	if (found == data.begin() && found->first != whatday)
		return 1;
	if (found == data.end() || (found->first != whatday))
		--found;
	std::cout << whatday << " => " << howmany << " = " << found->second * howmany << std::endl;
	return 0;
}

void	makeshitup(thisMap data, std::ifstream &file)
{
	std::string line;
	char *leftovers = NULL;

	std::getline(file, line);
	if (line == "date | value")
		std::getline(file, line);
	while (!file.eof())
	{
		if (line.length() < 14)
			std::cout << "Error: issue with line => " << line << std::endl;
		else if (decent_date(line))
			std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
		else if (strncmp(&line[10], " | ", 3) != 0)
			std::cout << "Error: bad format (date and value not separated by \" | \") => " << line;
		else {
			std::string whatday = line.substr(0, 10);
			double value = strtold(&line[12], &leftovers);
			if (value < 0 || value > 1000)
				std::cout << "Error: value not good => " << value << std::endl;
			else if (*leftovers != '\0')
				std::cout << "Error: shit in line => " << leftovers << std::endl;
			else if (make_calculations(data, value, whatday))
				std::cout << "Error: date is too early => " << whatday << std::endl;
		}
		std::getline(file, line);
	}
}


int	main(int argc, char **argv)
{
	std::ifstream database;
	std::ifstream inputfile;

	if (check_files(argc, argv, database, inputfile))
		return 1;
	try {
		maclasse classe._data = thisMap data = makeMap(database);
		makeshitup(data, inputfile);
	} 
	catch(const char *e) {
		std::cout << "error in database: " << e << std::endl;
	}	
}
