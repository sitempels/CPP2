
#ifndef		SCALARCONVERTER_HPP
# define	SCALARCONVERTER_HPP

/*Includes*/

class	ScalarConverter {
	public:
	/*Constructor - Copy Constructor - Destructor*/
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& copy_from) = delete;
		~ScalarConverter() = delete;

	/*Overloaded Operator*/
		ScalarConverter&	operator=(const ScalarConverter& other) = delete;

	/*Public Method*/
		static void	convert(const std::string literal) ;
};

#endif


#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string literal) {
	
}
