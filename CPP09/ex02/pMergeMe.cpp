#include "pMergeMe.hpp"

static std::vector<unsigned int>	sortPair(std::vector<unsigned int>& container, unsigned int elem_size);
static std::deque<unsigned int>		sortPair(std::deque<unsigned int>& container, unsigned int elem_size);
static unsigned int					calcJacobstal(unsigned int actual) ;

namespace fordJohnson {
	unsigned int g_comp = 0;
}

bool	fordJohnson::isValidInput(char** argv) {
	if (!argv[1] && !argv[1][0])
		return (false);
	int	i = 1;
	while (argv[i]) {
		int j = 0;
		while (argv[i][j]) {
			if (!std::isdigit(argv[i][j]) && !(argv[i][j] == ' '))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

std::vector<unsigned int>	fordJohnson::fillVectContainer(char** argv) {
	std::stringstream	stream;
	std::vector<unsigned int>	container;
	size_t	i = 1;
	while (argv[i]) {
		unsigned int	value;
		stream << argv[i];
		while (stream >> value) {
			container.push_back(value);
		}
		stream.clear();
		i++;
	}
	return (container);
}

std::deque<unsigned int>	fordJohnson::fillDeqContainer(char** argv) {
	std::stringstream	stream;
	std::deque<unsigned int>	container;
	size_t	i = 1;
	while (argv[i]) {
		unsigned int	value;
		stream << argv[i];
		while (stream >> value) {
			container.push_back(value);
		}
		stream.clear();
		i++;
	}
	return (container);
}

bool	fordJohnson::runAlgo(std::vector<unsigned int>& container, unsigned int	iteration) {
	//Create recursive pairs
	unsigned int	elem_size = fordJohnson::exponent(2, iteration);
	++iteration;
	unsigned int	elem_nbr = container.size() / elem_size;
	unsigned int	pair_nbr = elem_nbr / 2;

	//Recursively create and sort pair -> function is in recursive state onward
	if (pair_nbr < 1) {
		return (true);
	}
	else {
		//Sort with bigest pair as comparative value
		container = sortPair(container, elem_size);
		if (!runAlgo(container, iteration)) {
			container.clear();
			return (false);
		}
	}

	//Create main list with first smallest and all the bigest
	std::vector<std::vector<unsigned int>::iterator> main;
	main.push_back(container.begin() + (elem_size - 1));
	for (size_t i = 0; i < pair_nbr; ++i) {
		main.push_back(container.begin() + (2 * elem_size - 1) + (i * 2 * elem_size));
	}

	//Insert smallest pair following Jacobstal sequence
	unsigned int	prev_jacobs = 1;
	for (unsigned int	jacobs = 3; prev_jacobs < elem_nbr; jacobs = calcJacobstal(jacobs)) {
		for (unsigned int i = jacobs; i > prev_jacobs;  --i) { 
			if ((2 * i - 1) * elem_size - 1 >= container.size())
				continue ;
			std::vector<unsigned int>::iterator	elem = container.begin() + ((2 * i - 1) * (elem_size)) - 1;
			main.insert(lowerBound(main.begin(), main.end(), *elem), elem);
		}
		prev_jacobs = jacobs;
	}
	
	//Reorder container base on main order
	std::vector<unsigned int>	response;
	for (std::vector<std::vector<unsigned int>::iterator>::iterator it = main.begin(); it != main.end(); ++it) {
		for (int i = elem_size - 1; i >= 0; --i) {
			response.push_back(*(*it - i));
		}
	}

	//Add all non participating number
	size_t	size = elem_nbr * elem_size;
	if (size < container.size()) {
		for (std::vector<unsigned int>::iterator it = container.begin() + (size); it != container.end(); ++it) {
			response.push_back(*it);
		}
	}

	container = response;
	return (true);
}

bool	fordJohnson::runAlgo(std::deque<unsigned int>& container, unsigned int	iteration) {
	//Create recursive pairs
	unsigned int	elem_size = fordJohnson::exponent(2, iteration);
	++iteration;
	unsigned int	elem_nbr = container.size() / elem_size;
	unsigned int	pair_nbr = elem_nbr / 2;

	//Recursively create and sort pair -> function is in recursive state onward
	if (pair_nbr < 1) {
		return (true);
	}
	else {
		//Sort with bigest pair as comparative value
		container = sortPair(container, elem_size);
		if (!runAlgo(container, iteration)) {
			container.clear();
			return (false);
		}
	}

	//Create main list with first smallest and all the bigest
	std::deque<std::deque<unsigned int>::iterator> main;
	main.push_back(container.begin() + (elem_size - 1));
	for (size_t i = 0; i < pair_nbr; ++i) {
		main.push_back(container.begin() + (2 * elem_size - 1) + (i * 2 * elem_size));
	}

	//Insert smallest pair following Jacobstal sequence
	unsigned int	prev_jacobs = 1;
	for (unsigned int	jacobs = 3; prev_jacobs < elem_nbr; jacobs = calcJacobstal(jacobs)) {
		for (unsigned int i = jacobs; i > prev_jacobs;  --i) { 
			if ((2 * i - 1) * elem_size - 1 >= container.size())
				continue ;
			std::deque<unsigned int>::iterator	elem = container.begin() + ((2 * i - 1) * (elem_size)) - 1;
			main.insert(lowerBound(main.begin(), main.end(), *elem), elem);
		}
		prev_jacobs = jacobs;
	}
	
	//Reorder container base on main order
	std::deque<unsigned int>	response;
	for (std::deque<std::deque<unsigned int>::iterator>::iterator it = main.begin(); it != main.end(); ++it) {
		for (int i = elem_size - 1; i >= 0; --i) {
			response.push_back(*(*it - i));
		}
	}

	//Add all non participating number
	size_t	size = elem_nbr * elem_size;
	if (size < container.size()) {
		for (std::deque<unsigned int>::iterator it = container.begin() + (size); it != container.end(); ++it) {
			response.push_back(*it);
		}
	}

	container = response;
	return (true);
}

static unsigned int	calcJacobstal(unsigned int actual) {
	unsigned int	next = (fordJohnson::exponent(actual + 1, 2) - fordJohnson::exponent(-1, actual)) / 3;
	return (next);
}

static std::vector<unsigned int>	sortPair(std::vector<unsigned int>& container, unsigned int elem_size) {
	
	for (unsigned int pair_nbr = container.size() / (2 * elem_size); pair_nbr > 0; pair_nbr--) {
		std::vector<unsigned int>::iterator first_elem = container.begin() + (pair_nbr - 1) * (2 * elem_size); 
		std::vector<unsigned int>::iterator middle_elem = first_elem + elem_size; 
		std::vector<unsigned int>::iterator last_elem = container.begin() + (pair_nbr) * (2 * elem_size) - 1;
		if (*(middle_elem - 1) > *last_elem) {
			std::rotate(first_elem, middle_elem, last_elem + 1);
		}
		fordJohnson::g_comp++;
	}
	return (container);
}

static std::deque<unsigned int>		sortPair(std::deque<unsigned int>& container, unsigned int elem_size) {
	
	for (unsigned int pair_nbr = container.size() / (2 * elem_size); pair_nbr > 0; pair_nbr--) {
		std::deque<unsigned int>::iterator first_elem = container.begin() + (pair_nbr - 1) * (2 * elem_size); 
		std::deque<unsigned int>::iterator middle_elem = first_elem + elem_size; 
		std::deque<unsigned int>::iterator last_elem = container.begin() + (pair_nbr) * (2 * elem_size) - 1;
		if (*(middle_elem - 1) > *last_elem) {
			std::rotate(first_elem, middle_elem, last_elem + 1);
		}
		fordJohnson::g_comp++;
	}
	return (container);
}

unsigned int	fordJohnson::exponent(unsigned int base, unsigned int exponent) {
	unsigned int	res = 1;
	while (exponent > 0) {
		res *= base;
		exponent--;
	}
	while (exponent < 0) {
		res /= base;
		exponent++;
	}
	return (res);
}
