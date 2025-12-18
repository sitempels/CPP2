
#include <cstdlib>

#include "Span.hpp"

int	main() {
	std::cout << "\nTest VECTOR container:" << std::endl;

	{
		Span	span = Span(5);
		std::cout << &span << std::endl; 
		span.addNumber(5);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);
		try {
			span.addNumber(32);
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "\tshortest span: " << span.shortestSpan() << std::endl;
			std::cout << "\tlongest span: " << span.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\nTest VECTOR range(100):" <<std::endl;
		Span	span = Span(100);
		std::cout << &span << std::endl; 
		std::vector<int> vect;
		std::srand(time(NULL));
		for (int i = 0; i < 100; i++) {
			int	random_int = rand() % 1000000;
			vect.push_back(random_int);
		}
		try {
			span.addNumber(vect.begin(), vect.end());
			std::cout << "\tshortest span: " << span.shortestSpan() << std::endl;
			std::cout << "\tlongest span: " << span.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\nTest VECTOR range(10000):" <<std::endl;
		Span	span = Span(10000);
		std::cout << &span << std::endl; 
		std::vector<int> vect;
		std::srand(time(NULL));
		for (int i = 0; i < 100000; i++) {
			int	random_int = rand() % 1000000;
			vect.push_back(random_int);
		}
		try {
			span.addNumber(vect.begin(), vect.end());
			std::cout << "\tshortest span: " << span.shortestSpan() << std::endl;
			std::cout << "\tlongest span: " << span.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
