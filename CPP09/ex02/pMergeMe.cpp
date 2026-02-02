#include "pMergeMe.hpp"

static std::vector<unsigned int>	sortPair(std::vector<unsigned int>& container, unsigned int pair_size);
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
	unsigned int	pair_size = fordJohnson::exponent(2, iteration);
	++iteration;
	unsigned int	pair_nbr = container.size() / pair_size;

	//Recursively create and sort pair -> function is in recursive state onward
	if (container.size() / pair_size < 2) {
		return (true);
	}
	else {
		//Sort with bigest pair as comparative value
		container = sortPair(container, pair_size);
		if (!runAlgo(container, iteration)) {
			//error message ?
			container.clear();
			return (false);
		}
	}
	if (iteration > 0) {
		//Create main list
		std::vector<std::vector<unsigned int>::iterator> main;
		unsigned int main_size = container.size() / pair_size;
		main.push_back(container.begin() + (pair_size - 1));
		for (size_t i = 2; i <= main_size; i = i + 2) {
			main.push_back(container.begin() + (i * pair_size) - 1);
		}
		//Insert smallest pair following Jacobstal sequence
		//(2 exp(n + 1) + (-1) exp(n)) / 3
		
		unsigned int	prev_jacobs = 1;
		for (unsigned int	jacobs = 3; jacobs <= pair_nbr; jacobs = calcJacobstal(jacobs)) {
			for (unsigned int i = jacobs; i > prev_jacobs;  --i) { // binary insertion to do, diminish expected
				if ((2 * i - 1) * pair_size - 1 >= container.size())
					continue ;
				std::vector<unsigned int>::iterator	elem = container.begin() + ((2 * i - 1) * (pair_size)) - 1;
				std::vector<std::vector<unsigned int>::iterator>::iterator it = main.begin();
				while (it != main.end() && *elem > **it) {
					++it;
					fordJohnson::g_comp++;
				}
				if (it != main.end())
					main.insert(it, elem);
			}
			prev_jacobs = jacobs;
		}
		
		//Reorder container base on main order
		std::vector<unsigned int>	response;
		for (std::vector<std::vector<unsigned int>::iterator>::iterator it = main.begin(); it != main.end(); ++it) {
			for (int i = pair_size - 1; i >= 0; --i) {
				response.push_back(*(*it - i));
			}
		}

		for (std::vector<unsigned int>::iterator it = container.end() - (container.size() % pair_size); it != container.end(); ++it) {
			response.push_back(*it);
		}


		//Insert pend in reserve order
		//for ()
		container = response;
	}
	return (true);
}

static unsigned int	calcJacobstal(unsigned int actual) {
	unsigned int	next = (fordJohnson::exponent(actual + 1, 2) - fordJohnson::exponent(-1, actual)) / 3;
	return (next);
}

static std::vector<unsigned int>	sortPair(std::vector<unsigned int>& container, unsigned int pair_size) {
	
	for (unsigned int pair_nbr = container.size() / (2 * pair_size); pair_nbr > 0; pair_nbr--) {
		std::vector<unsigned int>::iterator first_elem = container.begin() + (pair_nbr - 1) * (2 * pair_size); 
		std::vector<unsigned int>::iterator middle_elem = first_elem + pair_size; 
		std::vector<unsigned int>::iterator last_elem = container.begin() + (pair_nbr) * (2 * pair_size) - 1;
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
