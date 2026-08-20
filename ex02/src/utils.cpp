
#include "PmergeMe.hpp"

unsigned int	packets_nb(vector &array, unsigned int packetsize)
{
	return array.size() / packetsize;
}

size_t	actual_index(unsigned int packetsize, unsigned int groupindex)
{
	if ((groupindex - 1) * packetsize < 0)
		return 0;
	return (groupindex - 1) * packetsize;
}

int	packet_value(vector &array, unsigned int packetsize, unsigned int groupindex)
{
	if (array.size() == actual_index(packetsize, groupindex) + packetsize - 1)
		return *(array.end() - 1);
	return array.at(actual_index(packetsize, groupindex) + packetsize - 1);
}

void	loser_packet(vector &array, unsigned int packetsize, unsigned int groupindex, vector &destination)
{
	vector::iterator target;
	target = array.begin() + actual_index(packetsize, groupindex);
	while (packetsize)
	{
		destination.push_back(*target);
		array.erase(target);
		--packetsize;
	}
}

// fancy swap - takes the first package and swaps it with the next one
void	merge(vector &array, unsigned int packetsize, unsigned int groupindex)
{
	vector::iterator target;
	vector temp;

	loser_packet(array, packetsize, groupindex, temp);
	print_vector(temp);
	target = array.begin() + actual_index(packetsize, groupindex + 1);
	array.insert(target, temp.begin(), temp.end());
}