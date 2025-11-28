/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:58:49 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 13:31:00 by stempels         ###   ########.fr       */
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
void	RobotomyRequestForm::doAction() const {
	int	random_number = rand() % 2;
	if (random_number == 1)
		std::cout << "Schhhlack ! " << target << " has been robotomized." << std::endl;
	else
		throw (RobotomizationFailed());
}

/*Exception*/
const char *RobotomyRequestForm::RobotomizationFailed::what() const throw() {
	return ("Could not be robotomized");
}
