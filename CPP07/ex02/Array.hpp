
#ifndef		ARRAY_HPP
# define	ARRAY_HPP

# include <exception>

template <typename T_array>
class	Array {
	public:
	/*Constructor - Copy Constructor - Destructor*/
		Array();
		Array(unsigned int n);
		Array(const Array& copy_from);
		~Array();

	/*Overloaded Operators*/
		Array&			operator=(const Array& other) ;
		T_array&		operator[](unsigned int i) ;
		const T_array&	operator[](unsigned int i) const ;
	
	/*Public Methods*/
		unsigned int	size() const ;

	/*Exceptions*/
		class	OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw() ;
		};
	
	private:
	/*Private Attributes*/
		T_array*		_array;
		unsigned int	_size;
};

# include "Array.tpp"

#endif
