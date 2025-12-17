
#include <iostream>
#include "Array.hpp"

int	main(void) {
	std::cout << "\nInt array:" << std::endl;
	{
	Array<int>	a;
	Array<int>	b(7);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	b[3] = 4;

	int	*bbis = new int[7];
	bbis[0] = 1;
	bbis[1] = 2;
	bbis[2] = 3;
	bbis[3] = 4;

	for (size_t i = 0; i < a.size(); i++) {
		std::cout << a[i] << std::endl;
	}
	try {
		a[0];
	}
	catch (...) {
		std::cerr << "An error was encountered" << std::endl;
	}
	std::cout << "Array<int> array:" << std::endl;
	for (size_t i = 0; i < b.size(); i++) {
		std::cout << "\t" << b[i] << std::endl;
	}
	std::cout << "Classic int array:" << std::endl;
	for (size_t i = 0; i < 7; i++) {
		std::cout << "\t"<< bbis[i] << std::endl;
	}
	delete[] bbis;
	}

	{
	std::cout << "\nChar array:" << std::endl;
	Array<char>	char_array(5);
	char_array[0] = 'e';
	for (size_t i = 0; i < char_array.size(); i++) {
		std::cout << "\t"<< char_array[i] << std::endl;
	}
	}

	{
	std::cout << "\nChar * array:" << std::endl;
	Array<char*>	str_array(2);
	str_array[0] = (char*)"Hello";
	str_array[1] = (char*)"World!";
	for (size_t i = 0; i < str_array.size(); i++) {
		std::cout << "\t"<< str_array[i] << std::endl;
	}
	}
	{
	std::cout << "\nWork with new array:" << std::endl;
	Array<int>	*c = new Array<int>(1);
	std::cout << "\t"<< (*c)[0] << std::endl;
	delete (c);
	}
	return (0);
}
