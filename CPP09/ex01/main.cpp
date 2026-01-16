
#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: one argument needed." << std::endl;
		return (1);
	}

	RPN	calc;

	if (!calc.resolve(argv[1]))
		return (1);
	std::cout << calc.getStack().top() << std::endl;
	return (0);
}
