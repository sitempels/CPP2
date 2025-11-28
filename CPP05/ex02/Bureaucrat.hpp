/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 06:27:39 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 13:16:28 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

/*Includes*/
# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

/*Macros*/
# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class	AForm ;

class	Bureaucrat {
	public:
		/*Constructors - Copy Constructor - Destructor*/
		Bureaucrat(std::string name = "default_name", int grade = LOWEST_GRADE) ;
		Bureaucrat(const Bureaucrat& copy_from) ;
		~Bureaucrat() ;

		/*Operator Overload*/
		Bureaucrat&	operator=(const Bureaucrat& other) ;

		/*Public methods*/
		void	incrementGrade() ;
		void	decrementGrade() ;
		void	signForm(AForm& form_to_sign) ;
		void	executeForm(AForm const & form) const ;

		/*Exceptions*/
		class	gradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw() ;
		};

		class	gradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw() ;
		};

		/*Getter - Setter*/
		const std::string	getName() const ;
		int					getGrade() const ;

	
	private:
		/*Private Attribute*/
		const std::string	name;
		int					grade;
};

std::ostream& operator<<(std::ostream& o_stream, const Bureaucrat& other) ;

#endif
