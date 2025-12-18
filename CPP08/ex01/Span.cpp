
#include "Span.hpp"

/*Constructor - Copy Constructor - Destructor*/
Span::Span() : N_(0) {}

Span::Span(unsigned int n) : N_(n) {}

Span::Span(const Span& copy_from) {
	if (this != &copy_from) {
		N_ = copy_from.N_;
		vect_ = copy_from.vect_;
	}
}

Span::~Span() {
	std::cout << "Destructor called: Span" << std::endl;
}

/*Overloaded Operators*/
Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		N_ = other.N_;
		vect_ = other.vect_;
	}
	return (*this);
}

/*Public Method*/
void	Span::addNumber(int n) {
	if (vect_.size() >= N_)
		throw (FullContainerException());
	vect_.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (vect_.size() + std::distance(begin, end) > N_)
		throw (FullContainerException());
	vect_.insert(vect_.end(), begin, end);
}

int	Span::shortestSpan() {
	if (vect_.size() <= 1)
		throw (NotEnoughContentException());
	std::vector<int>	tmp = vect_;
	std::sort(tmp.begin(), tmp.end());
	int	min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int	Span::longestSpan() {
	if (vect_.size() <= 1)
		throw (NotEnoughContentException());
	std::vector<int>	tmp = vect_;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char*	Span::FullContainerException::what() const throw() {
	return ("Container has no more space");
}

const char* Span::NotEnoughContentException::what() const throw() {
	return ("Not enough content in the container");
}
