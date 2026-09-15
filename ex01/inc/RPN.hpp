/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:24:28 by rlebigre          #+#    #+#             */
/*   Updated: 2026/09/15 18:06:59 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
 #define RPN_HPP

#include <string>
#include <iostream>
#include <stack>

// EASIER NAME FOR THE STACK
typedef std::stack<long> stack;

// COLORS
 #define RESET "\x1b[0m"
 #define RED "\x1B[1;91m"
 #define DBLUE "\x1b[1;36m"
 #define PURPLE "\x1B[1;35m"

// OPERATIONS
enum e_operations {
	PLUS = '+',
	MINUS = '-',
	MULTIPLY = '*',
	DIVIDE = '/'
};

// FUNCTIONS
long	process_line(std::string input);


#endif
