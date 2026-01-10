
#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: one argument needed." << std::endl;
		return (1);
	}

	RPN	calc;

	calc.setTokenList(argv[1]);
	std::cout << calc.getTokenList() << std::endl;
	if (!calc.resolve())
		return (1);
	return (0);
}
