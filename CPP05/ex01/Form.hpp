/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:55:46 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 08:49:37 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FORM_HPP
# define	FORM_HPP

/*Includes*/
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat ;

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
