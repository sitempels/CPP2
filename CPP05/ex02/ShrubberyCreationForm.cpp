/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:58:49 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 17:04:03 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*Constructor - Copy Constructor - Destructor*/
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: 	AForm("ShrubberyCreation", 145, 137),
		target(target) {

	std::cout << "Constructor called: ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy_from)
	:	AForm(copy_from),
		target(copy_from.target) {

	std::cout << "Copy Constructor called: ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor called: ShrubberyCreationForm" << std::endl;
}

/*Overloaded Operators*/
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

/*Public method*/
std::string	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (getStatus() == false)
		throw (isNotSignedException());
	if (getExecuteGrade() < executor.getGrade())
		throw (gradeTooLowException());
	std::ofstream out_file((target + std::string("_shrubbery")).c_str());
	if (out_file) {
		out_file << "    /\\    \n";
		out_file << "   /  \\   \n";
		out_file << "  /    \\  \n";
		out_file << " /      \\ \n";
		out_file << "/________\\\n";
		out_file << "    ||    \n";
		out_file << "    ||    \n";
		out_file << "    ||    \n";

		out_file.close();
		return ("Tree draw successfully !");
	}
	else
		throw (OpenFileException());
}

/*Exception*/
const char *ShrubberyCreationForm::OpenFileException::what() const throw() {
	return ("Could not open and write the file");
}
