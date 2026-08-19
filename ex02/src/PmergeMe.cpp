/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <rlebigre@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:53:11 by rlebigre          #+#    #+#             */
/*   Updated: 2026/08/18 18:49:21 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
static int nbcompare = 0;

std::deque<int>	jacobSequence(std::deque<int> &deque)
{
	int newJacob = 0;
	std::deque<int>	jacob;
	
	if (deque.size() == 2)
		return jacob;
	jacob.push_back(3);
	if (5 > deque.size())
		return jacob;
	jacob.push_back(5);
	while (1)
	{
		std::deque<int>::iterator n1 = jacob.end() - 1;
		std::deque<int>::iterator n2 = jacob.end() - 2;
		newJacob = *n1 + 2 * *n2;
		if (newJacob > deque.size())
			return jacob;
		jacob.push_back(newJacob);
	}
	return jacob;
}

// only hardcore coders know THIS one...............................
void ft_swap(std::deque<int>::iterator first, std::deque<int>::iterator second)
{
	int temp = *first;
	*first = *second;
	*second = temp; 
}

void big_and_small(int packetsize, std::deque<int> &deque)
{
	if (packetsize == deque.size());
		return ;
	for (std::deque<int>::iterator it = deque.begin(); it + packetsize < deque.end(); it + packetsize)
	{
		if (*it > *(it + packetsize))
			ft_swap(it, it + 1);
		++nbcompare;
	}
	big_and_small(packetsize * 2, deque);
}

std::deque<int> insertion(std::deque<int> &deque)
{
	std::deque<int> jacob = jacobSequence(deque);
	std::deque<int> sorted;

	sorted.push_back(deque.front());
	sorted.push_back(deque.at(1));
	// ou sont passé les chiffres !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	while (1)
	{
		if (jacob.empty())
			break ;
		
	}

}

int	sort_deque(std::deque<int> &deque)
{
	
	big_and_small(1, deque);
	std::deque<int> sorted = insertion(deque);

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
	int comparedeque = nbcompare;
	
	nbcompare = 0;
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
	std::cout << "Number of comparisons with std::deque = " << comparedeque << std::endl;
	std::cout << "Number of comparisons with std::list = " << nbcompare << std::endl;
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