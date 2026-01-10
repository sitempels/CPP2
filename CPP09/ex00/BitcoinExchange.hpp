
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

	/*Exceptions*/
		class CouldNotOpenFile : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("Could not open the following file:");
				}
		};

		class InvalidColumnFormat : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("Invalid column format.");
				}
		};

		class InvalidDateFormat : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("Invalid date format. Expect 'YYYY-MM-DD'");
				}
		};

		class InvalidPriceFormat : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("Invalid price format. Expect a number between 0.0 and 1000.0'");
				}
		};

		class DuplicateInDatabase : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("Duplicated date found in database.");
				}
		};

		class FatalErrorEncountered : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("Fatal error ! Abort everything !");
				}
		};

		private:
		/*Private Attribute*/
			std::map<unsigned int, double>	quotes_;

		/*Private Methods*/
			bool		validateDate(std::tm& date) const;
			bool		validateValue(const float& price) const;					
			void		printValue(const std::tm& date, const float& value) const ;
};

std::ostream&	operator<<(std::ostream& ostream, const std::tm& tm) ;

#endif
