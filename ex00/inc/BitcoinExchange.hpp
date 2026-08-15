/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre.42angouleme@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:24:28 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/15 19:12:53 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>

// EASIER NAME FOR THE MAP 
typedef std::map<std::string,double> thisMap;

// COLORS
 #define RESET "\x1b[0m"
 #define RED "\x1B[1;91m"
 #define DBLUE "\x1b[1;36m"
 #define PURPLE "\x1B[1;35m"
// MONTHS
enum e_months {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER,
};

// INPUT LINE BENCHMARKS
enum e_where {
	END_DATE = 10,
	START_VALUE = 11,
	MIN_LEN = 12,
};

// FORMAT
 #define DataFormat ","
 #define InputFormat " | "
 #define InputFormatLen 3

// FUNCTIONS
int								check_files(int argc, char **argv, std::ifstream &database, std::ifstream &input);
std::map<std::string,double>	make_map(std::ifstream &file);
void							study_input(thisMap data, std::ifstream &file);

#endif
