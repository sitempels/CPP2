
#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"

int	main() {
	{
		std::cout << "\nTest VECTOR container:" << std::endl;
		std::vector<int>	vector;

		for (int i = 0; i < 10; i++) {
			vector.push_back(i);
		}

		try {
			std::cout << *easyfind(vector, 5) << std::endl;
			std::cout << *easyfind(vector, 20) << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nTest LIST container:" << std::endl;
		std::list<int>	list;

		for (int i = 0; i < 15; i++) {
			list.push_back(i);
		}

		try {
			std::cout << *easyfind(list, 0) << std::endl;
			std::cout << *easyfind(list, 20) << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nTest DEQUE container:" << std::endl;
		std::deque<int>	deque;

		for (int i = 0; i < 10; i++) {
			deque.push_back(i);
		}

		try {
			std::cout << *easyfind(deque, 7) << std::endl;
			std::cout << *easyfind(deque, 20) << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
