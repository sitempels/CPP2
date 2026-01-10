
#ifndef		RPN_HPP
# define	RPN_HPP

/*Includes*/
# include <string>
# include <iostream>
# include <sstream>
# include <exception>
# include <stack>
# include <sys/types.h>

/*Enum*/
typedef	enum	e_type	{
	DIGIT,
	ADD,
	SUB,
	MUL,
	DIV,
}				t_type;

/*Struct*/
typedef struct	s_token {
	t_type	type;
	char	value;
}				t_token;

class	RPN {
	public:
	/*Default Constructor - Copy Constructor - Destructor*/
		RPN();
		RPN(const RPN& copy_from);
		~RPN();

	/*Overloaded Operator*/
		RPN&	operator=(const RPN& rhs);

	/*Public Methods*/
		bool	setTokenList(const char* input) ;
		bool	resolve();

	/*Getters*/
	std::stack<t_token>	getTokenList() const;

	private:
	/*Private Attributes*/
		std::stack<t_token>	token_list_;
	/*Private Methods*/
		bool	tokenizeInput(std::stringstream& input) ;
		void	cleanTokenList() ;
};

std::ostream&	operator<<(std::ostream& ostream, const t_token& token);
std::ostream&	operator<<(std::ostream& ostream, const std::stack<t_token> token_list);

#endif
