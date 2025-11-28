/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:47:14 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 17:04:24 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ROBOTOMYREQUESTFORM_HPP
# define	ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <stdlib.h>
# include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm {
	public:
		/*Constructor - Copy Constructor - Destructor*/
		RobotomyRequestForm(std::string target = "Default_target");
		RobotomyRequestForm(const RobotomyRequestForm& copy_from);
		~RobotomyRequestForm();

		/*Overloaded Operators*/
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

		/*Public method*/
		std::string	execute(Bureaucrat const & executor) const ;

	private:
		const std::string	target;
};

#endif
