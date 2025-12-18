
#ifndef		SPAN_HPP
# define	SPAN_HPP

/*Includes*/
# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class	Span {
	public:
	/*Constructor - Copy Constructor - Destructor*/
		Span();
		Span(unsigned int N);
		Span(const Span& copy_from);
		~Span();

	/*Overloaded Operator*/
		Span&	operator=(const Span& other) ;

	/*Public Methods*/
		int		shortestSpan() ;
		int		longestSpan() ;
		void	addNumber(int n) ;
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) ;

	/*Exceptions*/
		class	FullContainerException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class	NotEnoughContentException : public std::exception {
				virtual const char* what() const throw();
		};

	private:
		unsigned int		N_;
		std::vector<int>	vect_;
};

#endif
