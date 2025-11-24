/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 07:37:33 by stempels          #+#    #+#             */
/*   Updated: 2025/11/24 08:03:06 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*Constructor*/
Bureaucrat::Bureaucrat(std::string name, int new_grade) : name(name) {
		if (grade > LOWEST_GRADE)
			throw (gradeTooLowException());
		else if (grade < HIGHEST_GRADE)
			throw (gradeTooHighException());
		grade = new_grade;
		std::cout << *this;
}

/*Copy Constructor*/
Bureaucrat::Bureaucrat(const Bureaucrat& copy_from) : name(copy_from.name), grade(copy_from.grade) {}

/*Destructor*/
Bureaucrat::~Bureaucrat() {}

/*Overloaded Operators*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		grade = other.grade;
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
