/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:53:44 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 17:04:34 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SHRUBBERYCREATIONFORM_HPP
# define	SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm {
	public:
		/*Constructor - Copy Constructor - Destructor*/
		ShrubberyCreationForm(std::string target = "Default_target");
		ShrubberyCreationForm(const ShrubberyCreationForm& copy_from);
		~ShrubberyCreationForm();

		/*Overloaded Operators*/
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		/*Public method*/
		std::string	execute(Bureaucrat const & executor) const ;

		/*Exception*/
		class	OpenFileException : public std::exception {
			public:
				virtual const char*	what() const throw() ;
		};

	private:
		const std::string	target;
};

#endif
