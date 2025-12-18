
#include <iostream>
#include "iter.hpp"

void	exampleCharFunction(char *str) {
	std::cout << "char function: " << str << std::endl;
	return ;
}

void	exampleStringFunction(std::string str) {
	std::cout << "string function: " << str << std::endl;
	return ;
}

void	exampleIntFunction(int* i) {
	std::cout << "int function: " << i << std::endl;
	return ;
}

int	main(void) {
	std::cout << "\nChar array test:" << std::endl;
	char *char_array[] = {(char*)"Test1",(char*)"Test2",(char*)"Test3",(char*)"Test4",(char*)"Test5"};
	::iter<char*, void (*)(char*)>(char_array, 5, exampleCharFunction);

	std::cout << "\nString array test:" << std::endl;
	std::string string_array[] = {"Test1","Test2","Test3","Test4","Test5"};
	::iter<std::string, void (*)(std::string)>(string_array, 5, exampleStringFunction);

	std::cout << "\nInt array test:" << std::endl;
	int b[] = {1, 2, 3};
	int	*a[] = {b};
	::iter<int*, void (*)(int*)>(a, 1, exampleIntFunction);
	return (0);
}
