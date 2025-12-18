
#ifndef		EASYFIND_HPP
# define	EASYFIND_HPP

/*Includes*/
# include <algorithm>
# include <exception>

class	NotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Number not found");
		}
};

template <typename T>
typename T::iterator	easyfind(T& container, int n) ;

#include "easyfind.tpp"

#endif
