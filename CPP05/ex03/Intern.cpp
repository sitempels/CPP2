/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:59:45 by stempels          #+#    #+#             */
/*   Updated: 2025/12/02 13:59:51 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*Constructor - Copy Constructor - Destructor*/
Intern::Intern() {
	std::cout << "Constructor called: Intern" << std::endl;
}

Intern::Intern(const Intern& copy_from) {
	(void) copy_from;
	std::cout << "Copy Constructor called: Intern" << std::endl;
}

Intern::~Intern() {
	std::cout << "Destructor called: Intern" << std::endl;
}

/*Overloaded Operator*/
Intern&	Intern::operator=(const Intern& other) {
	(void) other;
	return (*this);
}

/*Public Method*/
AForm*	Intern::makeForm(std::string form_name, std::string form_target) {
	std::string	form_list[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm*	new_form = NULL;
	int i = 0;
	while (i < 3 && form_name != form_list[i])
		i++;
	switch (i) {
		case 0:
			new_form = new ShrubberyCreationForm(form_target);
			break ;
		case 1:
			new_form = new RobotomyRequestForm(form_target);
			break ;
		case 2:
			new_form = new PresidentialPardonForm(form_target);
			break ;
		default:
			throw (noFormFound());
	}
	std::cout << "Intern creates " << form_name <<  std::endl;
	return (new_form);
}

/*Exceptions*/
const char*	Intern::noFormFound::what() const throw() {
	return ("Intern found no form of that type");
}
