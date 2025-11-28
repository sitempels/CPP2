/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:48:56 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 17:01:40 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*Constructor - Copy Constructor - Destructor*/
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: 	AForm("PresidentialPardon", 25, 5),
		target(target) {

	std::cout << "Constructor called: PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy_from)
	:	AForm(copy_from),
		target(copy_from.target) {

	std::cout << "Copy Constructor called: PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor called: PresidentialPardonForm" << std::endl;
}

/*Overloaded Operators*/
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

/*Public method*/
std::string	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (getStatus() == false)
		throw (isNotSignedException());
	if (getExecuteGrade() < executor.getGrade())
		throw (gradeTooLowException());
	return (target + " has been pardonned by Zaphod Beeblebrox");
}
