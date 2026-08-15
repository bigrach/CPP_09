/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre.42angouleme@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/15 22:35:21 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	sort_deque(std::deque<int> &deque)
{
	

	
}
void	sort_list(std::list<int> &list)
{
	
}

void	print_deque(std::deque<int> &deque)
{
	std::cout << std::setw(10) << PURPLE "After : " << ' ' << std::flush;
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
		std::cout << *it << ' ' << std::flush;
	std::cout << RESET << std::endl;
}

void	car_rock_algo(std::deque<int> &deque, std::list<int> &list)
{
	std::time_t startdeque = std::time(nullptr);
	sort_deque(deque);
	std::time_t timedeque = startdeque - std::time(nullptr);

	std::time_t startList = std::time(nullptr);
	sort_list(list);
	std::time_t timeList = startList - std::time(nullptr);

	if (check_deque(deque))
		throw "deque is not sorted";
	if (check_list(list))
		throw "list is not sorted";
	print_deque(deque);

	std::cout << std::setw(40) << "Time to process a range of " << deque.size() << " elements with std::deque : " << timedeque << " us" << std::endl;
	std::cout << std::setw(40) << "Time to process a range of " << list.size() << " elements with std::list : " << timeList << " us" << std::endl;
}

int	check_deque(std::deque<int> &deque)
{
	for (std::deque<int>::iterator it = deque.begin(); it + 1 != deque.end(); ++it)
	{
		if (*it > *(it + 1))
			return 1;
	}
	return 0;
}

int	check_list(std::list<int> &list)
{
	for (std::list<int>::iterator it = list.begin(); ++it != list.end(); ++it)
	{
		if (*it > *(++it))
			return 1;
	}
	return 0;
}