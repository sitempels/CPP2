/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:29:51 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 17:41:26 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		INTERN_HPP
# define	INTERN_HPP

/*INCLUDES*/
# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
	/*Constructor - Copy Constructor - Destructor*/
		Intern();
		Intern(const Intern& copy_from);
		~Intern();

	/*Overloaded Operator*/
		Intern&	operator=(const Intern& other);
	
	/*Public Method*/
		AForm*	makeForm(std::string name_of_form, std::string target_of_form) ;

	/*Exceptions*/
	class	noFormFound : public std::exception {
		public:
			virtual const char*	what() const throw() ;
	};
};

#endif
