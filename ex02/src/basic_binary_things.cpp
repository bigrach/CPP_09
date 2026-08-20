#include "PmergeMe.hpp"

bool binary_search(vector &array, int searchingfor)
{
	int start = 0;
	int end = array.size();
	int midpoint = array.size() / 2;

	while (start < end)
	{
		if (searchingfor > array.at(midpoint))
			start = midpoint + 1;
		else
			end = midpoint - 1;
		midpoint = (end + start) / 2;
	}
	if ((size_t)start < array.size() && array[start] == searchingfor)
	{
		std::cout << "found" << std::endl;
		return true;
	}
	std::cout << "not found" << std::endl;
	return false;
}

bool binary_insert(vector &array, int number)
{
	int start = 0;
	int end = array.size();
	int midpoint = array.size() / 2;

	while (start < end)
	{
		if (number > array.at(midpoint))
			start = midpoint + 1;
		else
			end = midpoint - 1;
		midpoint = (end + start) / 2;
	}
	if (end < 0)
		end = 0;
	if ((size_t)(end + 1) > array.size())
		end = array.size();
	else
		end = ++end;
	vector::iterator target = array.begin() + end;
	array.insert(target, number);
	return false;
}