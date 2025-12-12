#include "ScalarConverter.class.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	std::cout << "Copy ScalarConverter constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor ScalarConverter called" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &src) {
	(void)src;
	std::cout << "Copy ScalarConverter assignment operator called" << std::endl;
	return *this;
}

void	printChar(char c, bool isPossible = true) {
	if (!isPossible)
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void	printInt(int i, bool isPossible = true) {
	if (!isPossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	printFloat(float f, bool isPossible = true) {
	if (!isPossible)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
}

void	printDouble(double d, bool isPossible = true) {
	if (!isPossible)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

bool	isPseudoLiteral(const std::string& str) {
	std::string pseudoLiterals[6] = {
			"-inff",
			"+inff",
			"nanf",
			"-inf",
			"+inf",
			"nan"
	};

	for (int i = 0; i < 6; i++) {
		if (str == pseudoLiterals[i])
			return true;
	}
	return false;
}

bool	isValid(const std::string& str) {
	int nbDots = 0;
	int nbF = 0;
	int nbSigns = 0;

	// 1. Check if the string is empty
	if (str.empty())
		return false;

	// 2. Check if the string is a single character
	if (str.length() == 1)
		return true;

	// 3. Check if the string is a pseudo-literal
	if (isPseudoLiteral(str))
		return true;

	for (size_t i = 0; i < str.length(); i++) {
		// 3. Check if the string contains only digits, a dot, a 'f' or a sign
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != '-' && str[i] != '+')
			return false;

		// Count the number of dots in the string
		if (str[i] == '.')
			nbDots++;

		// Count the number of 'f' in the string
		if (str[i] == 'f')
			nbF++;

		// Count the number of signs in the string
		if (str[i] == '-' || str[i] == '+')
			nbSigns++;

		// 4. Check if the string contains more than one dot, more than one 'f' or more than one sign
		if (nbDots > 1 || nbF > 1 || nbSigns > 1)
			return false;
	}
	return true;
}

void	toChar(const std::string& str) {
	char c;

	c = str[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

float	toFloat(std::string str) {
	// Permet de manipuler des chaînes de caractères comme si elles étaient
	// des flux d'entrée ou de sortie.
	std::stringstream ss1;
	std::stringstream ss2;
	float f;
	int	i;

	// Remove the 'f' at the end of the string with pop_back()
	str.pop_back();

	// Put the string into the stream
	ss1 << str;
	ss2 << str;

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

void	toDouble(const std::string& str) {
	std::stringstream ss1;
	std::stringstream ss2;
	double d;
	int i;

	ss1 << str;
	ss2 << str;

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

void	toInt(const std::string& str) {
	std::stringstream ss;
	int i;

	ss << str;
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

void	toPseudoLiteral(const std::string& str) {
	printChar('c', false);
	printInt(0, false);
	if (str == "-inff" || str == "+inff" || str == "nanf") {
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
	} else {
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& str) {

	// 1. Check if the string is valid
	if (!isValid(str)) {
		printChar('c', false);
		printInt(0, false);
		printFloat(0, false);
		printDouble(0, false);
		return;
	}

	// 2. Check pseudo-literals
	if (isPseudoLiteral(str)) {
		toPseudoLiteral(str);
		return;
	}

	// 3. Check if the string is a char
	if (str.length() == 1 && !isdigit(str[0]))
		toChar(str);
	// 4. Check if the string is a float or -inff, +inff or nanf
	else if (str.back() == 'f')
		toFloat(str);
	// 5. Check if the string is a double
	else if (str.find('.') != std::string::npos)
		toDouble(str);
	// 6. Check if the string is an int
	else
		toInt(str);
}
