#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: one argument expected." << std::endl;
		return (1);
	}
	BitcoinExchange	market;

/* 
	//Error testing on database usage
	std::cout << "\n--- No loaded database test ---\n" << std::endl;
	market.execute(argv[1]);

	std::cout << "\n--- Faulty database loaded ---\n" << std::endl;
	try {
		market.loadDatabase("faulty_database.csv");
		market.execute(argv[1]);	
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
*/

	std::cout << "\n--- Correct and loaded database ---\n" << std::endl;
	try {
		market.loadDatabase("data.csv");
		market.execute(argv[1]);	
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
