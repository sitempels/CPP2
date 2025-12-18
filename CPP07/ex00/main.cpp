#include <iostream>
#include "whatever.hpp"

int	main(void) {
	int	a = 2;
	int	b = 3;

	std::cout << "\nNumeric value:" << std::endl;
	std::cout << "\tAt first a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "\tAfter swap a = " << a << ", b = " << b << std::endl;
	std::cout << "\tmin(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "\tmax(a, b) = " << ::max(a, b) << std::endl;

	std::cout << "\nString value:" << std::endl;
	std::string	c = "Hello";
	std::string	d = "World!";

	std::cout << "\tAt first c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "\tAfter swap c = " << c << ", d = " << d << std::endl;
	std::cout << "\tmin(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "\tmax(c, d) = " << ::max(c, d) << std::endl;

	return (0);
}
