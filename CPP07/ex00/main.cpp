#include <iostream>
#include "whatever.hpp"

int	main(void) {
	int	a = 2;
	int	b = 3;

	std::cout << "At first a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string	c = "Hello";
	std::string	d = "World!";

	std::cout << "At first c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return (0);
}
