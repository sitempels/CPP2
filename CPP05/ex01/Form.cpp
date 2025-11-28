/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:54:47 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 09:30:26 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Form::Form(std::string name, int new_sign_grade, int new_execute_grade)
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
Form::Form(const Form& copy_from)
	:	name(copy_from.name),
		sign(copy_from.sign),
		sign_grade(copy_from.sign_grade),
		execute_grade(copy_from.execute_grade) {

	std::cout << "Copy constructor called: Form" << std::endl;
}

/*Destructor*/
Form::~Form() {
	std::cout << "Destructor called: Form" << std::endl;
}

/*Overloaded Operators*/
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		sign = other.sign;
	}
	return (*this);
}

/*Public Methods*/
void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getSignGrade())
		sign = 1;
	else
		throw (gradeTooLowException());
	return ;
}

/*Exceptions*/
const char*	Form::gradeTooLowException::what() const throw() {
	return ("Form grade too low");
}

const char*	Form::gradeTooHighException::what() const throw() {
	return ("Form grade too high");
}

/*Getters*/
std::string	Form::getName() const {
	return (name);
}

bool		Form::getStatus() const {
	return (sign);
}

int			Form::getSignGrade() const {
	return (sign_grade);
}

int			Form::getExecuteGrade() const {
	return (execute_grade);
}

/*Functions*/
std::ostream& operator<<(std::ostream& o_stream, const Form& other) {
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
