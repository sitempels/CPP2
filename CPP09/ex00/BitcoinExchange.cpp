
#include "BitcoinExchange.hpp"

/*Default Constructor*/
BitcoinExchange::BitcoinExchange() {}

/*Copy Constructor*/
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy_from) {
	if (this != &copy_from)
		*this = copy_from;
}

/*Destructor*/
BitcoinExchange::~BitcoinExchange() {}

/*Overloaded Operator*/
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this != &rhs)	
		quotes_ = rhs.quotes_;
	return (*this);
}

/*Public Method*/
void	BitcoinExchange::loadDatabase(const char* file_name) {
	//Try to open input file
	std::ifstream	stream(file_name);
	if (!stream.is_open())
		throw (std::runtime_error("Database: Could not open the file"));

	//Extract and verify header of input file
	std::string line;
	std::getline(stream, line);
	if (line != "date,exchange_rate")
		throw (std::runtime_error("Database: Invalid column format"));

	//Parse header file and print Value of bitcoin/Error accordingly
	size_t				nbr_line = 1;
	double				price;
	std::tm 			date = {};
	std::stringstream	sstream;

	while (!stream.eof()) {
		line.clear();
		sstream.clear();
		sstream.str("");
		price = -1;
		date.tm_year = 0;
		std::getline(stream, line);
		if (stream.fail())
			break ;
		sstream << line;
		sstream	>> std::noskipws
				>> date;
		if (sstream.fail() || sstream.get() != ',')
			throw (std::runtime_error("Database: Invalid column format")); 
		try {
			validateDate(date);
		}
		catch (const std::exception& e) {
			std::string	error_msg("Database: ");
			throw (std::runtime_error(error_msg + e.what()));
		}
		sstream >> std::noskipws >> price;
		if (price == -1)
			throw (std::runtime_error("Database: Invalid price format"));
		unsigned int	uint_date = (((date.tm_year * 100) + (date.tm_mon)) * 100) + date.tm_mday;
		std::pair<std::map<unsigned int, double>::iterator, bool>	check;
		check = quotes_.insert(std::make_pair(uint_date, price));
		if (!check.second) {
			quotes_.clear();
			throw (std::runtime_error("Database: Duplicate"));
		}
		nbr_line++;
	}
	//End of file reached
	if (stream.eof())
		return ;
	//Something went REALLY wrong
	else
		throw (std::runtime_error("Database: Fatal error encountered"));
}

void	BitcoinExchange::execute(const char* file_name) {
	//Check if a database was loaded
	if (quotes_.empty()) {
		std::cerr << "Error: a database is needed.\n\tLoad one with: loadDatabase(const char* path_to_database)." << std::endl;
		return ;
	}
	//Try to open input file
	std::ifstream	stream(file_name);
	if (!stream.is_open())
		throw (std::runtime_error("Input: Could not open file"));

	//Extract and verify header of input file
	std::string line;
	std::getline(stream, line);
	if (line != "date | value")
		throw (std::runtime_error("Input: Invalid column format"));

	//Parse header file and print Value of bitcoin/Error accordingly
	char				sep = ' ';
	float				value;
	std::tm 			date = {};
	std::stringstream	sstream;

	while (!stream.eof()) {
		sep = ' ';
		line.clear();
		sstream.clear();
		sstream.str("");
		value = std::numeric_limits<float>::quiet_NaN();
		date.tm_year = 0;
		std::getline(stream, line);
		if (stream.fail())
			break ;
		sstream << line;
		sstream >> date;
		sstream >> sep;
		if (sstream.fail() || sep != '|') {
			std::cerr	<< "Input Error: bad format." << std::endl;
			continue ;
		}
		try {
			validateDate(date);
		}
		catch (const std::exception& e) {
			std::cerr << "Input Error: " << e.what() << std::endl;
			continue ;
		}
		sstream >> value;
		if (sstream.fail()) {
			std::cerr << "Input Error: missing numeric value. Expect positive integer or float." << std::endl;
			continue ;
		}
		try {
			validateValue(value);
		}
		catch (const std::exception& e) {
			std::cerr << "Input Error: " << e.what() << std::endl;
			continue ;
		}
		printValue(date, value);
	}
	//End of file reached
	if (stream.eof())
		return ;
	//Something went REALLY wrong
	else
		throw (std::runtime_error("Fatal error encountered"));
}

/*Private Methods*/
void	BitcoinExchange::validateDate(std::tm& data) const {
		std::tm	tmp = data; 
		(void)mktime(&data);
		if (tmp != data) {
			std::stringstream stream;
			stream << "invalid date => " << tmp << "\n";
			std::string	error;
			std::getline(stream, error);	
			throw (std::runtime_error(error));
		}
		return ;
}

void	BitcoinExchange::validateValue(const float& value) const { 
	if (value != value)
		throw (std::runtime_error("invalid value. Expect positive integer or float."));
	else if (value < 0.0)
		throw (std::runtime_error("not a positive value."));
	else if (value > 1000.0)
		throw (std::runtime_error("too large a number."));
	else
		return ;
}

void	BitcoinExchange::printValue(const std::tm& date, const float& value) const {
	unsigned int	uint_date = 0;
	std::map<unsigned int, double>::const_iterator	last = quotes_.end();
	std::map<unsigned int, double>::const_iterator	target;

	uint_date = (((date.tm_year * 100) + (date.tm_mon)) * 100) + date.tm_mday;

	target = quotes_.find(uint_date); 
	if (target == last) {
		target = quotes_.upper_bound(uint_date);
		if (target == quotes_.begin()) {
			std::cerr << "Input Error: no data available for that date.\n Date precede the first date available." << std::endl;
			return ;
		}
		target--;
	}
	std::cout << date << " => " << value << " = " << value * target->second << std::endl;
	return ;
}

/*Getter*/
const std::map<unsigned int, double>&	BitcoinExchange::getQuotes() const {
	return (quotes_);
}

std::ostream&	operator<<(std::ostream& ostream, const std::tm& tm) {
	ostream << tm.tm_year + 1900 << "-" << tm.tm_mon + 1 << "-" << tm.tm_mday;
	return (ostream);
}

std::istream&	operator>>(std::istream& istream, std::tm& tm) {
		char	separator[3] = {};
		istream	>> tm.tm_year >> separator[0]
				>> tm.tm_mon >> separator[1]
				>> tm.tm_mday;
		if (separator[0] != '-'
			|| separator[1] != '-') {
			istream.setstate(std::ios::failbit);
		}
		tm.tm_year -= 1900;
		tm.tm_mon -= 1;
	return (istream);
}

bool	operator==(const std::tm& lhs, const std::tm& rhs) {
	if (lhs.tm_year == rhs.tm_year && lhs.tm_mon == rhs.tm_mon && lhs.tm_mday == rhs.tm_mday)	
		return (true);
	return (false);
}

bool	operator!=(const std::tm& lhs, const std::tm& rhs) {
	return (!(lhs == rhs));
}
