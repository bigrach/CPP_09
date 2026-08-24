/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basics.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:00:49 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/24 18:34:21 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_vector(vector &vector)
{
	for (vector::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << *it << ' ' << std::flush;
	std::cout << RESET << std::endl;
}

bool	is_sorted_vector(vector &array)
{
	for (vector::iterator it = array.begin(); it + 1 != array.end(); ++it)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}