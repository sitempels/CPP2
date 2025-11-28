/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 07:37:33 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 08:56:52 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*Constructor*/
Bureaucrat::Bureaucrat(std::string name, int new_grade) : name(name) {
		if (new_grade > LOWEST_GRADE)
			throw (gradeTooLowException());
		else if (new_grade < HIGHEST_GRADE)
			throw (gradeTooHighException());
		else {
			grade = new_grade;
			std::cout << "Constructor hired: " << *this;
		}
}

/*Copy Constructor*/
Bureaucrat::Bureaucrat(const Bureaucrat& copy_from) : name(copy_from.name), grade(copy_from.grade) {
			std::cout << "Copy constructor hired: " << *this;
}

/*Destructor*/
Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor fired: " << *this;
}

/*Overloaded Operators*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		grade = other.grade;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& o_stream, const Bureaucrat& other) {
	o_stream << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (o_stream);
}

/*Public Methods*/
void	Bureaucrat::incrementGrade() {
	if (grade == HIGHEST_GRADE)
		throw gradeTooHighException();
	else
		grade--;
	return ;
}

void	Bureaucrat::decrementGrade() {
	if (grade == LOWEST_GRADE)
		throw gradeTooLowException();
	else
		grade++;
	return ;
}

void	Bureaucrat::signForm(Form& form_to_sign) {
	try {
		form_to_sign.beSigned(*this);
	}
	catch (const std::exception& e) {
		std::cout << name << " couldn't sign " << form_to_sign.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << name << " signed " << form_to_sign.getName() << std::endl;
	return ;
}

/*Exceptions*/
const char*	Bureaucrat::gradeTooLowException::what() const throw() {
	return ("Bureaucrat grade too low");
}

const char*	Bureaucrat::gradeTooHighException::what() const throw() {
	return ("Bureaucrat grade too high");
}

/*Getter*/
const std::string	Bureaucrat::getName() const {
	return (name);
}

int		Bureaucrat::getGrade() const {
	return (grade);
}
