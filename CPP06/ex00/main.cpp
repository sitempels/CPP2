
#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: 1 argument needed" << argc - 1 << " provided." << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
