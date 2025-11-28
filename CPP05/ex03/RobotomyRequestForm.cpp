/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:58:49 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 17:03:12 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*Constructor - Copy Constructor - Destructor*/
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: 	AForm("RobotomyRequest", 145, 137),
		target(target) {

	std::cout << "Constructor called: RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy_from)
	:	AForm(copy_from),
		target(copy_from.target) {

	std::cout << "Copy Constructor called: RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor called: RobotomyRequestForm" << std::endl;
}

/*Overloaded Operators*/
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

/*Public method*/
std::string	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (getStatus() == false)
		throw (isNotSignedException());
	if (getExecuteGrade() < executor.getGrade())
		throw (gradeTooLowException());
	int	random_number = rand() % 2;
	if (random_number == 1)
		return ("Schhhlack ! " + target + " has been robotomized.");
	else
		return ("Sch...clang ! " + target + " robotomization failed.");
}
