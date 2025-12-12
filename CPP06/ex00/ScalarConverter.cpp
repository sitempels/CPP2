
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy_from) {
	(void)copy_from;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return (*this);
}

void	ScalarConverter::convert(const std::string& literal) {
	char	*end;

	if (literal == "nan" || literal == "nanf") {
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: nanf\n"
					<< "double: nan\n" << std::endl;
		return ;
	}

	else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: +inff\n"
					<< "double: +inf\n" << std::endl;
		return ;
	}

	else if (literal == "-inf" || literal == "-inff") {
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: -inff\n"
					<< "double: -inf\n" << std::endl;
		return ;
	}

