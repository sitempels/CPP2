
#ifndef		SCALARCONVERTER_HPP
# define	SCALARCONVERTER_HPP

/*Includes*/
# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>

class	ScalarConverter {
	public:
	/*Public Method*/
		static void	convert(const std::string literal) ;

	private:
	/*Constructor - Copy Constructor - Destructor*/
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy_from);
		~ScalarConverter();

	/*Overloaded Operator*/
		ScalarConverter&	operator=(const ScalarConverter& other);
};

#endif
