/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:05:00 by stempels          #+#    #+#             */
/*   Updated: 2025/12/12 11:32:36 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called: ScalarConverter" << std::endl;
}


ScalarConverter::ScalarConverter(ScalarConverter const& copy_from) {
	(void)copy_from;
	std::cout << "Copy constructor called: ScalarConverter" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Default destructor called: ScalarConverter" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const& other) {
	(void)other;
	return (*this);
}

template <typename From, typename To>
int	is_convertible(From value) {
	if (std::numeric_limits<From>::is_iec559) {
		if (value != value)
			return (2);
	}	
	if (std::numeric_limits<To>::is_iec559) {
		if (value < -std::numeric_limits<To>::max()
			|| std::numeric_limits<To>::max() < value)
		return (1);
	}
	else if (value < std::numeric_limits<To>::min()
		|| std::numeric_limits<To>::max() < value)
		return (1);
	return (0);
}

void	printChar(char c, int action) {
	switch (action) {
		case (0):
			if ((0 <= c && c < 32) || c == 127)
				std::cout << "char: Non displayable" << std::endl;
			else if (c < 0)
				std::cout << "char: impossible" << std::endl;
			else
				std::cout << "char: '" << c << "'" << std::endl;
			break ;
		case (1):
			std::cout << "char: overflow" << std::endl;
			break ;
		default:
			std::cout << "char: impossible" << std::endl;
	}
}

void	printInt(int c, int action) {
	switch (action) {
		case (0):
				std::cout << "int: '" << c << "'" << std::endl;
				break ;
		case (1):
			std::cout << "int: overflow" << std::endl;
			break ;
		default:
			std::cout << "int: impossible" << std::endl;
	}
}

void	printFloat(float c, int action) {
	switch (action) {
		case (0):
				std::cout << std::fixed << std::setprecision(1) << "float: '" << c << "f'" << std::endl;
				break ;
		case (1):
			std::cout << "float: overflow" << std::endl;
			break ;
		default:
			std::cout << "float: impossible" << std::endl;
	}
}

void	printDouble(double c, int action) {
	switch (action) {
		case (0):
				std::cout << std::fixed << std::setprecision(1) << "double: '" << c << "'" << std::endl;
				break ;
		case (1):
			std::cout << "double: overflow" << std::endl;
			break ;
		default:
			std::cout << "double: impossible" << std::endl;
	}
}

bool	isPseudoLiteral(const std::string& literal) {
	std::string pseudoLiterals[6] = {
	"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	int i = 0;
	while (i < 6) {
		if (literal == pseudoLiterals[i])
			return true;
		i++;
	}
	return false;
}

bool	isValid(const std::string& literal) {
	int nbDots = 0;
	int nbF = 0;
	int nbSigns = 0;

	if (literal.empty())
		return false;
	if	(literal.length() == 1
		|| isPseudoLiteral(literal))
		return true;

	size_t	i = 0;
	while (i < literal.length()) {
		if (literal.at(i) == '.')
			nbDots++;
		else if (literal.at(i) == 'f')
			nbF++;
		else if (literal.at(i) == '-' || literal.at(i) == '+')
			nbSigns++;
		else if (!isdigit(literal.at(i)))
			return (false);
		if (nbDots > 1 || nbF > 1 || nbSigns > 1)
			return false;
		i++;
	}
	return true;
}

void	toChar(const std::string& literal) {
	char c;

	c = literal.at(0);

	printChar(c, 0);
	printInt(static_cast<int>(c), is_convertible<char, int>(c));
	printFloat(static_cast<float>(c), is_convertible<char, float>(c));
	printDouble(static_cast<double>(c), is_convertible<char, double>(c));
}


void	toInt(const std::string& literal) {
	std::stringstream ss;
	int i;

	ss << literal;
	ss >> i;

	printChar(static_cast<char>(i), is_convertible<int, char>(i));

	if (ss.fail())
		printInt(0, 1);
	else
		printInt(i, 0);

	printFloat(static_cast<float>(i), is_convertible<int, float>(i));
	printDouble(static_cast<double>(i), is_convertible<int, double>(i));

	ss.clear();
}

void	toFloat(const std::string& literal) {
	std::stringstream ss;
	float f;

	ss << literal;
	ss >> f;

	printChar(static_cast<char>(f), is_convertible<float, char>(f));
	printInt(static_cast<int>(f), is_convertible<float, int>(f));

	if (ss.fail())
		printFloat(0, 1);
	else
		printFloat(f, 0);

	printDouble(static_cast<double>(f), is_convertible<float, double>(f));

	ss.clear();
}
void	toDouble(const std::string& literal) {
	std::stringstream ss;
	double d;

	ss << literal;
	ss >> d;

	 printChar(static_cast<char>(d), is_convertible<double, char>(d));
	 printInt(static_cast<int>(d), is_convertible<double, int>(d));
	 printFloat(static_cast<float>(d), is_convertible<double, float>(d));

	if (ss.fail())
		printDouble(0, 1);
	else
		printDouble(d, 0);

	ss.clear();
}

void	toPseudoLiteral(const std::string& literal) {
	printChar(0, 2);
	printInt(0, 2);
	if	(literal == "-inff"
		||	literal == "+inff"
		|| literal == "nanf") {
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	}
	else {
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
}

void	ScalarConverter::convert(const std::string literal) {
	if (isPseudoLiteral(literal)) {
		toPseudoLiteral(literal);
	}
	else if (!isValid(literal)) {
		std::cerr << "Invalid string." << std::endl;
		return;
	}
	else if (literal.length() == 1 && !isdigit(literal.at(0)))
		toChar(literal);
	else if (literal.at(literal.size() - 1) == 'f')
		toFloat(literal);
	else if (literal.find('.') != std::string::npos)
		toDouble(literal);
	else
		toInt(literal);
}
