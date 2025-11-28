/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:53:44 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 17:04:15 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PRESIDENTIALPARDONFORM_HPP
# define	PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm {
	public:
		/*Constructor - Copy Constructor - Destructor*/
		PresidentialPardonForm(std::string target = "Default_target");
		PresidentialPardonForm(const PresidentialPardonForm& copy_from);
		~PresidentialPardonForm();

		/*Overloaded Operators*/
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		/*Public method*/
		std::string	execute(Bureaucrat const & executor) const ;

	private:
		const std::string	target;
};

#endif
