
#ifndef		BITCOINEXCHANGE_HPP
# define	BITCOINEXCHANGE_HPP

/*Includes*/
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <exception>
# include <ctime>

class	BitcoinExchange {
	public:
	/*Default Constructor - Copy Constructor - Destructor*/
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy_from);
		~BitcoinExchange();

	/*Overloaded Operator*/
		BitcoinExchange&	operator=(const BitcoinExchange& rhs) ;

	/*Public Methods*/
		void		execute(const char* filename) ;
		void		loadDatabase(const char* file_name) ;

	/*Getter*/
		const std::map<unsigned int, double>&	getQuotes() const;

		private:
		/*Private Attribute*/
			std::map<unsigned int, double>	quotes_;

		/*Private Methods*/
			bool		validateDate(std::tm& date) const;
			bool		validateValue(const float& price) const;					
			void		printValue(const std::tm& date, const float& value) const ;
};

std::ostream&	operator<<(std::ostream& ostream, const std::tm& tm) ;
std::istream&	operator>>(std::istream& istream, std::tm& tm) ;
bool			operator==(const std::tm& lhs, const std::tm& rhs) ;
bool			operator!=(const std::tm&lhs, const std::tm& rhs) ;

#endif
