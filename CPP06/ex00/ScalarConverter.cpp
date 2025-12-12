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

void	printChar(char c, bool is_possible = true) {
	if ((0 < c && c < 32) || c == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (!is_possible || c < 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void	printInt(int i, bool is_possible = true) {
	if (!is_possible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	printFloat(float f, bool is_possible = true) {
	if (!is_possible)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
}

void	printDouble(double d, bool is_possible = true) {
	if (!is_possible)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
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

	c = literal[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void	toInt(const std::string& literal) {
	std::stringstream ss;
	int i;

	ss << literal;
	ss >> i;
	printChar(static_cast<char>(i));
	if (ss.fail())
		printInt(0, false);
	else
		printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
	ss.clear();
}

float	toFloat(std::string literal) {
	// Permet de manipuler des chaînes de caractères comme si elles étaient
	// des flux d'entrée ou de sortie.
	std::stringstream ss1;
	std::stringstream ss2;
	float f;
	int	i;

	literal.erase(literal.size() - 1);

	// Put the string into the stream
	ss1 << literal;
	ss2 << literal;

	// Extract the float and the int from the stream
	ss1 >> i;
	ss2 >> f;

	printChar(static_cast<char>(f));
	if (ss1.fail())
		printInt(0, false);
	else
		printInt(static_cast<int>(f));
	if (ss2.fail())
		printFloat(0, false);
	else
		printFloat(f);
	printDouble(static_cast<double>(f));

	// Clear the stream
	ss1.clear();
	ss2.clear();

	return f;
}

void	toDouble(const std::string& literal) {
	std::stringstream ss1;
	std::stringstream ss2;
	int		i;
	double	d;

	ss1 << literal;
	ss2 << literal;

	ss1 >> i;
	ss2 >> d;
	printChar(static_cast<char>(d));
	if (ss1.fail())
		printInt(0, false);
	else
		printInt(static_cast<int>(d));
	printFloat(static_cast<float>(d));
	if (ss2.fail())
		printDouble(0, false);
	else
		printDouble(d);
	ss1.clear();
	ss2.clear();
}

void	toPseudoLiteral(const std::string& literal) {
	printChar('c', false);
	printInt(0, false);
	if	(literal == "-inff"
		||	literal == "+inff"
		|| literal == "nanf") {
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	} else {
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
