/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:55:46 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 13:13:29 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AFORM_HPP
# define	AFORM_HPP

/*Includes*/
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat ;

class	AForm {
	public:
		/*Constructor - Copy Constructor - Destructor*/
		AForm(std::string name = "Default_form", int grade_to_sign = 150, int grade_to_execute = 150) ;
		AForm(const AForm& copy_from);
		virtual ~AForm() ;

		/*Operator Overload*/
		AForm&	operator=(const AForm& other) ;

		/*Public Method*/
		void	beSigned(const Bureaucrat& bureaucrat) ;
		void	execute(Bureaucrat const & executor) const ;

		/*Exceptions*/
		class	gradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw() ;
		};

		class	gradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw() ;
		};

		class	isNotSignedException : public std::exception {
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

	protected:
		/*Protected Method*/
		virtual void	doAction() const = 0 ;
};

std::ostream& operator<<(std::ostream& o_stream, const AForm& other) ;

#endif
