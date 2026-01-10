
#include "RPN.hpp"

/*Default Constructor - Copy Constructor - Destructor*/
RPN::RPN() {}

RPN::RPN(const RPN& copy_from) {
	this->token_list_ = copy_from.token_list_;
}

RPN::~RPN() {}

/*Overloaded Operators*/
RPN&	RPN::operator=(const RPN& rhs) {
	if (this != &rhs) {
		this->token_list_ = rhs.getTokenList();
	}
	return (*this);
}

/*Public Methods*/
bool	RPN::setTokenList(const char* input) {
	if (!token_list_.empty())
		cleanTokenList();

	std::stringstream	stream(input);
	if (!tokenizeInput(stream))
		return (false);
	return (true);
}

bool	RPN::resolve() {
	if (token_list_.empty()) {
		std::cerr << "Error: no calculation to do" << std::endl;
		return (false);
	}
	ssize_t	number[3] = {};
	int	index = -1;
	t_token	current;
	while (!token_list_.empty()) {
		current = token_list_.top();
		switch (current.type) {
			case (DIGIT):
				if (index >= 3) {
					cleanTokenList();
					std::cerr << "Error: unexpected digit: " << current.value << std::endl; 
					return (false);
				}
				index++;
				number[index] = current.value - 48;
				break ;
			case (ADD):
				if (index <= 0) {
					cleanTokenList();
					std::cerr << "Error: unexpected operation: " << current.value << std::endl; 
					return (false) ;
				}
				index--;
				number[index] += number[index + 1];
				break ;
			case (SUB):
				if (index <= 0) {
					cleanTokenList();
					std::cerr << "Error: unexpected operation: " << current.value << std::endl; 
					return (false) ;
				}
				index--;
				number[index] -= number[index + 1];
				break ;
			case (MUL):
				if (index <= 0) {
					cleanTokenList();
					std::cerr << "Error: unexpected operation: " << current.value << std::endl; 
					return (false) ;
				}
				index--;
				number[index] *= number[index + 1];
				break ;
			case (DIV):
				if (index <= 0) {
					cleanTokenList();
					std::cerr << "Error: unexpected operation: " << current.value - 48 << std::endl; 
					return (false) ;
				}
				if (number[index] == 0) {
					std::cerr << "Error: Attempt at division by 0" << std::endl;
					return (false);
				}
				index--;
				number[index] /= number[index + 1];
				break ;
		}
		token_list_.pop();
	}
	if (index != 0) {
		std::cerr << "Error: excedentary token." << std::endl;
		return (false);
	}
	std::cout << number[0] << std::endl;
	return (true);
}
/*Getter*/
std::stack<t_token>	RPN::getTokenList() const {
	return (token_list_);
}

/*Private Methods*/
bool	RPN::tokenizeInput(std::stringstream& input) {
	char	c;
	input >> std::noskipws >> c;
	if (input.fail())
		return (input.eof());
	if (!tokenizeInput(input))
		return (false);

	t_token	token = {};
	if (std::isdigit(c))
		token.type = DIGIT;
	else {
		switch (c) {
			case ('+'):
				token.type = ADD;
				break ;
			case ('-'):
				token.type = SUB;
				break ;
			case ('*'):
				token.type = MUL;
				break ;
			case ('/'):
				token.type = DIV;
				break ;
			case (' '):
				return (true) ;
			default:
				cleanTokenList();
				std::cerr	<< "Error: Unexpected character '"
							<< c << "'" << std::endl;
				return (false);
		}
	}
	token.value = c;
	(this->token_list_).push(token);
	return (true);
}

void	RPN::cleanTokenList() {
	while (!(this->token_list_).empty())
		(this->token_list_).pop();
}

std::ostream&	operator<<(std::ostream& ostream, const t_token& token) {
		ostream << token.type << "\t" << token.value;
	return (ostream);
}

std::ostream&	operator<<(std::ostream& ostream, std::stack<t_token> token_list) {
	int	token_nbr = 0;
	while (!token_list.empty()) {
		ostream	<< "token n: " << token_nbr++ << "\t"
				<< token_list.top() << "\n";
		token_list.pop();
	}
	return (ostream);
}
