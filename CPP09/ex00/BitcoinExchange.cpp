
#include "BitcoinExchange.hpp"

/*Constructor*/
BitcoinExchange::BitcoinExchange(const char* database) {
	loadDatabase(database);
}

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
void	BitcoinExchange::execute(const char* file_name) {
	//Try to open input file
	std::ifstream	stream(file_name);
	if (!stream.is_open())
		throw (BitcoinExchange::CouldNotOpenFile());

	//Extract and verify header of input file
	std::string line;
	std::getline(stream, line);
	if (line != "date | value")
		throw (BitcoinExchange::InvalidColumnFormat());

	//Parse header file and print Value of bitcoin/Error accordingly
	char				separator[4];
	float				value;
	std::tm 			date;
	std::stringstream	sstream;

	while (!stream.eof()) {
		line.clear();
		sstream.clear();
		separator[3] = separator[2] = separator[1] = separator[0] = ' ';
		value = -1;
		date.tm_year = 0;
		std::getline(stream, line);
		if (stream.fail())
			break ;
		sstream << line;
		sstream	>> std::noskipws
				>> date.tm_year >> separator[0]
				>> date.tm_mon >> separator[1]
				>> date.tm_mday >> separator[2];
		if ((sstream.fail() && !sstream.eof())
			|| separator[0] != '-'
			|| separator[1] != '-'
			|| separator[2] != '|') {
			std::cerr	<< "Error: bad format." << std::endl;
			continue ;
		}
		if (!validateDate(date)) {
			continue ;
		}
		sstream >> std::noskipws >> value >> separator[3];
		if (separator[3] != '\n') {
			std::cerr	<< "Error: bad format." << std::endl;
			continue ;
		}
		if (!validateValue(value))
			continue ;
		printValue(date, value);
	}
	//End of file reached
	if (stream.eof())
		return ;
	//Something went REALLY wrong
	else
		throw (BitcoinExchange::FatalErrorEncountered());
}

/*Private Default Constructor*/
BitcoinExchange::BitcoinExchange() {}

/*Private Methods*/
void	BitcoinExchange::loadDatabase(const char* file_name) {
	//Try to open input file
	std::ifstream	stream(file_name);
	if (!stream.is_open())
		throw (BitcoinExchange::CouldNotOpenFile());

	//Extract and verify header of input file
	std::string line;
	std::getline(stream, line);
	if (line != "date | value")
		throw (BitcoinExchange::InvalidColumnFormat());

	//Parse header file and print Value of bitcoin/Error accordingly
	char				separator[4];
	double				price;
	std::tm 			date;
	std::stringstream	sstream;

	while (!stream.eof()) {
		line.clear();
		sstream.clear();
		separator[3] = separator[2] = separator[1] = separator[0] = ' ';
		price = -1;
		date.tm_year = 0;
		std::getline(stream, line);
		if (stream.fail())
			break ;
		sstream << line;
		sstream	>> std::noskipws
				>> date.tm_year >> separator[0]
				>> date.tm_mon >> separator[1]
				>> date.tm_mday >> separator[2];
		if ((sstream.fail() && !sstream.eof())
			|| separator[0] != '-'
			|| separator[1] != '-'
			|| separator[2] != ',') {
			throw (BitcoinExchange::InvalidColumnFormat()); 
		}
		if (!validateDate(date))
			throw (BitcoinExchange::InvalidDateFormat());
		sstream >> std::noskipws >> price >> separator[3];
		if (separator[3] != '\n')
			throw (BitcoinExchange::InvalidColumnFormat()); 
		if (!validateValue(price))
			throw (BitcoinExchange::InvalidPriceFormat());
		unsigned int	uint_date = (((date.tm_year * 10000) + (date.tm_mon)) * 100) + date.tm_mday;
		std::pair<std::map<unsigned int, double>::iterator, bool>	check;
		check = quotes_.insert(std::make_pair(uint_date, price));
		if (!check.first->second) {
			quotes_.clear();
			throw (BitcoinExchange::DuplicateInDatabase());
		}
	}
	//End of file reached
	if (stream.eof())
		return ;
	//Something went REALLY wrong
	else
		throw (BitcoinExchange::FatalErrorEncountered());
}

bool	BitcoinExchange::validateDate(std::tm& date) const {
		date.tm_year -= 1900;
		date.tm_mon -= 1;
		if (mktime(&date) == -1) {
			std::cerr	<< "Error: bad input => " << date << std::endl;
			return (false);
		}
		return (true);
}

bool	BitcoinExchange::validateValue(const float& value) const { 
	if (value == -1) {
		std::cerr << "Error: invalid value format. Expect integer or float." << std::endl;
		return (false) ;
	}
	else if (value < 0.0) {
		std::cerr << "Error: not a positive number." << std::endl;	
		return (false) ;
	}
	else if (value > 1000.0) {
		std::cerr << "Error: too large a numbe." << std::endl;
		return (false) ;
	}
	else
		return (true);
}

void	BitcoinExchange::printValue(const std::tm& date, const float& value) const {
	unsigned int	uint_date = 0;
	std::map<unsigned int, double>::const_iterator	last = quotes_.end();
	std::map<unsigned int, double>::const_iterator	target;

	uint_date = (((date.tm_year * 10000) + (date.tm_mon)) * 100) + date.tm_mday;

	target = quotes_.find(uint_date); 
	if (target == last) {
		target = quotes_.upper_bound(uint_date);
		if (target == quotes_.begin()) {
			std::cerr << "Error: no data available for that date." << std::endl;
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
