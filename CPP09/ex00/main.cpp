#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: one argument expected." << std::endl;
		return (1);
	}
	BitcoinExchange	market;

	market.execute(argv[1]);
	try {
		market.loadDatabase("data.csv");
		market.execute(argv[1]);	
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
