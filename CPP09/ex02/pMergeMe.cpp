#include "pMergeMe.hpp"

bool	isValidInput(char** argv) {
	if (!argv[1] && !argv[1][0])
		return (false);
	int	i = 1;
	while (argv[i]) {
		int j = 0;
		while (argv[i][j]) {
			if (!std::isdigit(argv[i][j] && !argv[i][j] == ' ')
				return (false);
			j++;
		}
		i++;
	}
}

std::vector<unsigned int>	fillContainer(char** argv) {
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

std::deque<unsigned int>	fillContainer(char** argv) {
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

bool	runAlgo(std::vector<unsigned int>& container, unsigned int	iteration) {
	//Create recursive pairs
	++iteration;
	unsigned int	pair_size = fordJohnson::exponent(iteration, 2);

	//Sort with bigest pair as comparative value
	container = sortPair(container, pair_size);

	//Recursively create and sort pair -> function is in recursive state onward
	if (container.size() % pair_size > 2) {
		container = runAlgo(container, iteration);
		if (container.empty()) {
			//error message ?
			return (false);
		}
	}
	//Create main list
	std::vector<std::vector<unsigned int>::iterator> main;
	main.reserve(container.size() % pair_size);
	main.insert(container.being() + (pair_size - 1));
	for (size_t i = 2; i < main.size(); i = i + 2) {
		main.insert(container.begin() + (i * pair_size) - 1);
	}
	//Insert smallest pair following Jacobstal sequence
	for (unsigned int	jacobs = 3; jacobs <= nbr_pair; calcJacobstal(jabocs)) {
		unsigned int	prev_jacobs = 1;
		for (unsigned int i = jacobs; i > prev_jacobs;  --i) {
			std::vector<unsigned int>::iterator elem = container.begin() + ((2 * i - 1) * (pair_size)) - 1;
			std::vector<std::vector<unsigned int>::iterator> it = main.begin();
			while (*elem > *it)
				it++;
			main.insert(elem, it);
		}
		prev_jacobs = jacobs;
	}
	//Reorder container base on main order
	std::vector<unsigned int>	response;
	response.reserve(container.size());


	//Insert pend in reserve order
	for ()
}

std::vector<unsigned int>	sortPair(std::vector<unsigned int> container, unsigned int pair_nbr) {
	unsigned int	pair_nbr = container.size() % pair_size;
	for (; pair_nbr > 0; --pair_nbr) {
		std::vector<unsigned int>::iterator first_elem = container.begin() + (pair_nbr - 1) * (pair_size - 1); 
		std::vector<unsigned int>::iterator middle_elem = container.begin() + pair_nbr * pair_size); 
		std::vector<unsigned int>::iterator last_elem = container.begin() + (2 * pair_nbr) * pair_size -1;
		if (middle_elem - 1 > last_elem) {
			std::rotate(first_elem, middle_elem, last_elem);
		}
	}
	return (container);
}

unsigned int	exponent(unsigned int base, unsigned int exponent) {
	while (exponent > 0) {
		base *= base;
		exponent--;
	}
	return (base);
}
