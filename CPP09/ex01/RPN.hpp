/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:56:15 by stempels          #+#    #+#             */
/*   Updated: 2026/01/16 16:58:15 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RPN_HPP
# define	RPN_HPP

/*Includes*/
# include <string>
# include <iostream>
# include <sstream>
# include <exception>
# include <stack>
# include <sys/types.h>

class	RPN {
	public:
	/*Default Constructor - Copy Constructor - Destructor*/
		RPN();
		RPN(const RPN& copy_from);
		~RPN();

	/*Overloaded Operator*/
		RPN&	operator=(const RPN& rhs);

	/*Public Methods*/
		bool	resolve(const char* input) ;

	/*Getters*/
	std::stack<int>	getStack() const;

	private:
	/*Private Attributes*/
		std::stack<int>	stack;
	/*Private Methods*/
		bool	isValidEndState(const std::stringstream& stream);
};

std::ostream&	operator<<(std::ostream& ostream, std::stack<int> stack_copy) ;

#endif
