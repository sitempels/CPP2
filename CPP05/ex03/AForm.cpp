/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:54:47 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 16:38:46 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*Constructor*/
AForm::AForm(std::string name, int new_sign_grade, int new_execute_grade)
	:	name(name),
		sign(false),
		sign_grade(new_sign_grade),
		execute_grade(new_execute_grade) {

	if (new_sign_grade > LOWEST_GRADE || new_execute_grade > LOWEST_GRADE)
		throw (gradeTooLowException());
	else if (new_sign_grade < HIGHEST_GRADE || new_execute_grade < HIGHEST_GRADE)
		throw (gradeTooHighException());
	std::cout << "Constructor: \n" << *this;
}

/*Copy Constructor*/
AForm::AForm(const AForm& copy_from)
	:	name(copy_from.name),
		sign(copy_from.sign),
		sign_grade(copy_from.sign_grade),
		execute_grade(copy_from.execute_grade) {

	std::cout << "Copy constructor called: AForm" << std::endl;
}

/*Destructor*/
AForm::~AForm() {
	std::cout << "Destructor called: AForm" << std::endl;
}

/*Overloaded Operators*/
AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		sign = other.sign;
	}
	return (*this);
}

/*Public Methods*/
void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (sign_grade >= bureaucrat.getGrade())
		sign = 1;
	else
		throw (gradeTooLowException());
	return ;
}

/*Exceptions*/
const char*	AForm::gradeTooLowException::what() const throw() {
	return ("grade is too low");
}

const char*	AForm::gradeTooHighException::what() const throw() {
	return ("grade is too high");
}

const char*	AForm::isNotSignedException::what() const throw() {
	return ("form isn't signed");
}

/*Getters*/
std::string	AForm::getName() const {
	return (name);
}

bool		AForm::getStatus() const {
	return (sign);
}

int			AForm::getSignGrade() const {
	return (sign_grade);
}

int			AForm::getExecuteGrade() const {
	return (execute_grade);
}

/*Functions*/
std::ostream& operator<<(std::ostream& o_stream, const AForm& other) {
	o_stream << "Form: " << other.getName() << "\n"
		<< "Status: ";
	if (other.getStatus())
		o_stream << "signed\n";
	else
		o_stream << "unsigned\n";
	o_stream << "Grade required to sign: " << other.getSignGrade() << "\n"
	<< "Grade required to execute: " << other.getExecuteGrade()
	<< std::endl;
	return (o_stream);
}
