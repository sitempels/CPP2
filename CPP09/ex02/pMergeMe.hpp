#ifndef		PMERGEME_HPP
# define	PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>

namespace fordJohnson {
	bool						isValidInput(char** argv) ;
	unsigned int				exponent(unsigned int base, unsigned exponent) ;

	std::vector<unsigned int>	fillContainer(char** argv) ;
	bool						runAlgo(std::vector<unsigned int>& container) ;
	std::vector<unsigned int>	sortPair(std::vector<unsigned int> container, unsigned int pair_nbr) ;

	std::deque<unsigned int>	fillContainer(char** argv) ;
	bool						runAlgo(std::deque<unsigned int>& container, unsigned int iteration = 0) ;
}

#endif
