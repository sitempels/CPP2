/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:55:46 by stempels          #+#    #+#             */
/*   Updated: 2025/11/25 11:25:12 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FORM_HPP
# define	FORM_HPP

/*Includes*/
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	Form {
	public:
		/*Constructor - Copy Constructor - Destructor*/
		Form(std::string name = "Default_form", int grade_to_sign = 150, int grade_to_execute = 150) ;
		Form(const Form& copy_from);
		~Form() ;

		/*Operator Overload*/
		Form&	operator=(const Form& other) ;

		/*Public Method*/
		void	beSigned(const Bureaucrat& bureaucrat) ;

		/*Exceptions*/
		class	gradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw() ;
		};

		class	gradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw() ;
		};

		/*Getters*/
		std::string	getName() const;
		bool		getStatus() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

	private:
		/*Private Attributes*/
		const std::string	name;
		bool				sign;
		const int			sign_grade;
		const int			execute_grade;
};

std::ostream& operator<<(std::ostream& o_stream, const Form& other) ;

#endif

#include "Bureaucrat.hpp"

Form::Form(std::string name, int sign_grade, int execute_grade)
		if (new_grade > LOWEST_GRADE)
			throw (gradeTooLowException());
		else if (new_grade < HIGHEST_GRADE)
			throw (gradeTooHighException());
		else {
			grade = new_grade;
			std::cout << "Constructor: Form: " << *this;
		}
}

/*Copy Constructor*/
Form::Form(const Form& copy_from) : name(copy_from.name), grade(copy_from.grade) {
			std::cout << "Copy constructor: Form: " << *this;
}

/*Destructor*/
Form::~Form() {
	std::cout << "Destructor: Form: " << *this;
}

/*Overloaded Operators*/
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		grade = other.grade;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& o_stream, const Form& other) {
	o_stream << "Form: " << other.getName() << "\n";
		<< "Status: ";
	if (getStatus)
		<< "signed\n";
	else
		<< "unsigned\n";
	<< "Grade required to sign: " << getSignGrade() << "\n";
	<< "Grade required to execute: " << getExecuteGrade();
	<< std::endl;
	return (o_stream);
}

