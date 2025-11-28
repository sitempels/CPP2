/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:47:14 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 13:48:14 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ROBOTOMYREQUESTFORM_HPP
# define	ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include <stdlib.h>
//# include <time.h>
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
		void	doAction() const;

		/*Exception*/
		class	RobotomizationFailed : public std::exception {
			public:
				virtual const char*	what() const throw() ;
		};

	private:
		const std::string	target;
};

#endif
