/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/15 18:32:03 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <limits.h>
#include <cstdlib>

int	isSign(const unsigned int c)
{
	return (c == MULTIPLY || c == PLUS || c == MINUS || c == DIVIDE);
}

int isSignOrDigit(const unsigned int c)
{
	return (isSign(c) || isdigit(c));
}

int	surgery(stack &numbers, unsigned int c)
{
	long	second = numbers.top();
	numbers.pop();
	long	first = numbers.top();
	numbers.pop();

	switch (c)
	{
		case MULTIPLY:
			numbers.push(first * second);
			break;

		case PLUS:
			numbers.push(first + second);
			break;

		case MINUS:
			numbers.push(first - second);
			break;

		case DIVIDE:
			if (second == 0)
				return 1;
			numbers.push(first / second);
			break;
	}
	return 0;
}

long	process_line(std::string input)
{
	int	i = 0;

	stack	numbers;
	while (input[i])
	{
		if (i % 2 != 0 && input[i] != ' ')
			throw "expected space";
		if (i % 2 == 0 && !isSignOrDigit(input[i]))
			throw "expected digit or sign";
		if (isdigit(input[i]))
			numbers.push(std::atoi(&input[i]));
		else if (isSign(input[i]))
		{
			if (numbers.size() < 2)
				throw "not enough numbers for calculation";
			if (surgery(numbers, input[i]))
				throw "dividing by zero is a no-no";
		}
		i++;
	}
	if (numbers.size() > 1)
		throw "missing operations";
	if (input[i - 1] == ' ')
		throw "extra space";
	return numbers.top();
}