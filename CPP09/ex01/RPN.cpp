
#include "RPN.hpp"

/*Default Constructor - Copy Constructor - Destructor*/
RPN::RPN() {}

RPN::RPN(const RPN& copy_from) {
	this->stack = copy_from.stack;
}

RPN::~RPN() {}

/*Overloaded Operators*/
RPN&	RPN::operator=(const RPN& rhs) {
	if (this != &rhs) {
		this->stack = rhs.getStack();
	}
	return (*this);
}

bool	RPN::resolve(const char* input) {
	std::stringstream					stream(input);
	char								ope;

	while (stream >> ope) {
		if (isdigit(ope))
			stack.push(ope - 48);
		else if (!(ope == '*' || ope == '/' || ope == '-' || ope == '+')) {
			std::cerr << "Error: Invalid operand: " << ope << std::endl;
			return (false);
		}
		else if (stack.size() < 2) {
			std::cerr << "Error: Operator in excess: " << ope << std::endl;
			return (false);
		}
		else {
			int	num_2 = stack.top();
			stack.pop();
			int num_1 = stack.top();
			stack.pop();
			switch (ope) {
				case ('+'):
					num_1 += num_2;
					break ;
				case ('-'):
					num_1 -= num_2;
					break ;
				case ('*'): 
					num_1 *= num_2;
					break ;
				case ('/'):
					if (num_2 == 0) {
						std::cerr << "Error: Attempting to divide by 0, don´t do that!" << std::endl;
						return (false);	
					}
					num_1 /= num_2;
					break ;
				}
				stack.push(num_1);
		}
	}
	return (isValidEndState(stream));	
}

bool	RPN::isValidEndState(const std::stringstream& stream) {
	if (!stream.eof())
		return (false);
	if (stack.size() > 1) {
		std::cerr << "Error: Excessive number of numbers" << std::endl;
		return (false);
	}
	return (true);
}

/*Getter*/
std::stack<int>	RPN::getStack() const {
	return (stack);
}

std::ostream&	operator<<(std::ostream& ostream, std::stack<int> stack_copy) {
	while (!stack_copy.empty()) {
		ostream << stack_copy.top();
		stack_copy.pop();
	}
	return (ostream);
}
