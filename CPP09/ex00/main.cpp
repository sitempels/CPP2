#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: one argument expected." << std::endl;
		return (1);
	}
	BitcoinExchange	market;

	std::cout << "\nTry without loading a database\n" << std::endl;
	market.execute(argv[1]);

	std::cout << "\nTry with a faulty database loaded\n" << std::endl;
	try {
		market.loadDatabase("data2.csv");
		market.execute(argv[1]);	
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nTry with a database loaded\n" << std::endl;
	try {
		market.loadDatabase("data.csv");
		market.execute(argv[1]);	
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
