#include "PmergeMe.hpp"

void test(vector &array)
{
	(void)array;
	binaryinsertpackage_tests();
	binaryinsert_tests();

}

void binaryinsertpackage_tests(void)
{
	std::cout << PURPLE "trying binary insert (packgsize = 2, 2nd packt)" RESET << std::endl;
	int jacobint[5] = {1, 3, 5, 11};
	vector jacob(&jacobint[0], &jacobint[4]);
	int numbers[6] = {1, 4, 3, 7, 8, 11};
	vector loser(&numbers[0], &numbers[6]);
	int numbers2[5] = {2, 5, 6, 9, 10};
	vector winner(&numbers2[0], &numbers2[5]);
	std::cout << "jacob = " << std::endl;
	print_vector(jacob);
	std::cout << "loser = " << std::endl;
	print_vector(loser);
	std::cout << "winner = " << std::endl;
	print_vector(winner);

	std::cout << PURPLE "packg binary insert packt size = 2, losergroupindex = 2" RESET << std::endl;
	package_binary_insert(winner, jacob, 2, loser, 2);
	print_vector(winner);
}

void	binaryinsert_tests(void)
{
	vector array;
	for (int i = -1; i < 11; ++i)
		array.push_back(i);
	std::cout << PURPLE "binary insert" RESET << std::endl;
	std::cout << "binary insert - inserting 5" << std::endl;
	binary_insert(array, 5);
	print_vector(array);
	std::cout << "binary insert - inserting 1" << std::endl;
	binary_insert(array, 1);
	print_vector(array);
	std::cout << "binary insert - inserting 11" << std::endl;
	binary_insert(array, 11);
	print_vector(array);
	std::cout << "binary insert - inserting 12" << std::endl;
	binary_insert(array, 12);
	print_vector(array);
}

void	packetinsertindex_tests(vector &array)
{
	std::cout << PURPLE "insert packet at index" RESET << std::endl;
	int numbers[7] = {78, 98, 65, 45, 12, 32, 10};
	vector test(&numbers[0], &numbers[7]);
	print_vector(test);
	print_vector(array);
	std::cout << "packet insert - packetsize = 2, dest index = 2, og index = 3" << std::endl;
	insert_packet_at_index(array, 2, 2, test, 3);
	print_vector(array);
	std::cout << "packet insert - packetsize = 3, dest index = 1, og index = 2" << std::endl;
	print_vector(test);
	print_vector(array);
	insert_packet_at_index(array, 3, 1, test, 1);
	print_vector(array);
}

void	binarysearch_tests(vector &array)
{
	std::cout << PURPLE "binary search" RESET << std::endl;
	std::cout << "binary search - looking for 1" << std::endl;
	binary_search(array, 1);
	std::cout << "binary search - looking for 5" << std::endl;
	binary_search(array, 5);
	std::cout << "binary search - looking for 11" << std::endl;
	binary_search(array, 11);
}

void	countingpackets_tests(vector &array)
{
	std::cout << PURPLE "testing counting packets nb" RESET << std::endl;
	std::cout << "packetsize = 1, packetnb = " << packets_nb(array, 1) << std::endl;
	std::cout << "packetsize = 5, packetnb = " << packets_nb(array, 5) << std::endl;
}

void	actualindex_tests()
{
	std::cout << PURPLE "testing actual index" RESET << std::endl;
	std::cout << "packetsize = 1, groupindex = 5, actual index = " << actual_index(1, 5) << std::endl;
	std::cout << "packetsize = 3, groupindex = 2, actual index = " << actual_index(3, 2) << std::endl;
}

void	packetvalue_tests(vector &array)
{
	(void)array;
	int onze[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	vector test(&onze[0], &onze[11]);
	std::cout << PURPLE "testing packet value" RESET << std::endl;
	print_vector(test);
	std::cout << "packetsize = 1, groupindex = 5, packet value = " << packet_value(test, 1, 5) << std::endl;
	std::cout << "packetsize = 3, groupindex = 2, packet value  = " << packet_value(test, 3, 2) << std::endl;
	std::cout << "packetsize = 2, groupindex = 6, packet value = " << packet_value(test, 2, 6) << std::endl;
	std::cout << "packetsize = 2, groupindex = 5, packet value  = " << packet_value(test, 2, 5) << std::endl;

}

void loserpackage_tests(vector &array)
{
	std::cout << PURPLE "testing loser package" RESET << std::endl;
	vector destination;
	std::cout << "packetsize = 1, groupindex = 5" << std::endl;
	print_vector(array);
	loser_packet(array, 1, 5, destination);
	print_vector(array);
	print_vector(destination);
}

void	merge_tests(vector &array)
{
	std::cout << PURPLE "testing merge" RESET << std::endl;
	std::cout << "packetsize = 1, groupindex = 4" << std::endl;
	print_vector(array);
	merge(array, 1, 4);
	print_vector(array);
	std::cout << "packetsize = 2, groupindex = 3" << std::endl;
	print_vector(array);
	merge(array, 2, 3);
	print_vector(array);
}


/*

void	car_rock_algo(std::vector<int> &vector, std::list<int> &list)
{
	//std::time_t startvector = std::time(nullptr);
	sort_vector(vector);
	//std::time_t timevector = startvector - std::time(nullptr);
	//int comparevector = nbcompare;

	nbcompare = 0;
	std::time_t startList = std::time(nullptr);
	sort_list(list);
	std::time_t timeList = startList - std::time(nullptr);

	if (check_vector(vector))
		throw "vector is not sorted";
	if (check_list(list))
		throw "list is not sorted";
	print_vector(vector);

	std::cout << std::setw(40) << "Time to process a range of " << vector.size() << " elements with std::vector : " << timevector << " us" << std::endl;
	std::cout << std::setw(40) << "Time to process a range of " << list.size() << " elements with std::list : " << timeList << " us" << std::endl;
	std::cout << "Number of comparisons with std::vector = " << comparevector << std::endl;
	std::cout << "Number of comparisons with std::list = " << nbcompare << std::endl;

}*/