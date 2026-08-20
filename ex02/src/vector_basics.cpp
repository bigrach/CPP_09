#include "PmergeMe.hpp"

void	print_vector(std::vector<int> &vector)
{
	std::cout << std::setw(10) << PURPLE "After : " << ' ' << std::flush;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << *it << ' ' << std::flush;
	std::cout << RESET << std::endl;
}

bool	is_sorted_vector(std::vector<int> &array)
{
	for (vector::iterator it = array.begin(); it + 1 != array.end(); ++it)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}