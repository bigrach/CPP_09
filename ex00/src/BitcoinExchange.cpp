/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/15 17:55:02 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstring>
#include <limits.h>
#include <cstdlib>

bool	is_leapyear(int year)
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int	check_date_validity(std::string input)
{
	const size_t BASE = 10;

	int year = std::strtol(input.c_str(), NULL, BASE);
	int month = std::strtol(&input[5], NULL, BASE);
	int day = std::strtol(&input[8], NULL, BASE);

	switch (month)
	{
		case APRIL: case JUNE: case SEPTEMBER: case NOVEMBER:
			return (day > 30);

		case JANUARY: case MARCH: case MAY: case JULY: case AUGUST: case OCTOBER: case DECEMBER:
			return (day > 31);

		case FEBRUARY:
			if (is_leapyear(year))
				return (day > 29);
			return (day > 28);

		default:
			return 1;
	}
}

int	decent_date(std::string input)
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

map	make_map(std::ifstream &file)
{
	std::string line;
	map currentMap;
	
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw "Missing 'date,exchange_rate' first line";
	while (!file.eof())
	{
		std::getline(file, line);
		if (line[0] == '\0')
			continue ;
		if (line.length() < MIN_LEN)
			throw "Line not long enough to have all data.";
		if (decent_date(line))
			throw "Invalid date.";
		if (line[10] != *DataFormat)
			throw "Invalid format.";
		char *leftovers = NULL;
		double value = strtold(&line[START_VALUE], &leftovers);
		if (*leftovers != '\0')
			throw "Shit at the end of the line.";

		currentMap[line.substr(0, END_DATE)] = value; 
	}
	return currentMap;
}

int	make_calculations(map data, double howmany, std::string &whatday)
{
	map::iterator found = data.lower_bound(whatday);
	if (found == data.begin() && found->first != whatday)
		return 1;
	if (found == data.end() || (found->first != whatday))
		--found;
	std::cout << DBLUE << whatday << " => " << howmany << " = " << found->second * howmany << RESET << std::endl;
	return 0;
}

void	study_input(map data, std::ifstream &file)
{
	std::string line;
	char *leftovers = NULL;

	std::getline(file, line);
	if (line != "date | value")
		throw "Missing 'date | value' first line in input file.";
	while (!file.eof())
	{
		std::getline(file, line);
		if (line.length() < 14)
			std::cout << RED "Error: bad input => " PURPLE "'" << line << "'" RESET << std::endl;
		else if (decent_date(line))
			std::cout << RED "Error: date is invalid => " PURPLE "'" << line.substr(0, 10) << "'" RESET << std::endl;
		else if (strncmp(&line[10], InputFormat, InputFormatLen) != 0)
			std::cout << RED "Error: bad format (date and value not separated by ' | ') => " PURPLE "'" << line << "'" RESET << std::endl;
		else {
			std::string whatday = line.substr(0, 10);
			double value = strtold(&line[12], &leftovers);
			if (value < 0)
				std::cout << RED "Error: not a positive number => " PURPLE "'" << value << "'" RESET << std::endl;
			else if (value > (double)1000)
				std::cout << RED "Error: too large a number => " PURPLE "'" <<  value << "'" RESET << std::endl;
			else if (*leftovers != '\0')
				std::cout << RED "Error: shit in line => " PURPLE "'" << leftovers << "'" RESET << std::endl;
			else if (make_calculations(data, value, whatday))
				std::cout << RED "Error: date is too early => " PURPLE "'" << whatday << "'" RESET << std::endl;
		}
	}
}