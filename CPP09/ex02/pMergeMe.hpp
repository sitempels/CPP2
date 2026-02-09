#ifndef		PMERGEME_HPP
# define	PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>

namespace fordJohnson {
	typedef struct	s_pair {
		size_t			id;
		unsigned int	small_container_idx;
		unsigned int	small_idx;
		unsigned int	big_container_idx;
		unsigned int	big_idx;

	}				t_pair;

	bool						isValidInput(char** argv) ;
	unsigned int				exponent(unsigned int base, unsigned int exponent) ;

	std::vector<unsigned int>	fillVectContainer(char** argv) ;
	bool						runAlgo(std::vector<unsigned int>& container, unsigned int iteration = 0) ;

	std::deque<unsigned int>	fillDeqContainer(char** argv) ;
	bool						runAlgo(std::deque<unsigned int>& container, unsigned int iteration = 0) ;

	//global for comparaison counter
	extern unsigned int g_comp;

	template <typename Iterator, typename T>
	Iterator lowerBound(Iterator first, Iterator last, const T& value) ;
}

# include "pMergeMe.tpp"

#endif
