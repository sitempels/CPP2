/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 07:40:00 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 13:56:24 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	{
		std::cout << "\nTest ex00\n" << std::endl;
		std::cout << "Highest grade possible: " << HIGHEST_GRADE << std::endl;
		std::cout << "Lowest grade possible: " << LOWEST_GRADE << std::endl;

		std::cout << "\nTest too high and too low creation:\n" << std::endl;
		try {
			Bureaucrat Sleeper1("Bern", 1500);
		}
		catch(const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		try {
			Bureaucrat Sleeper2("Olaf", -10);
		}
		catch(const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		std::cout << "\nTest increasing:\n" << std::endl;
		Bureaucrat bob("Bob", 2);
		std::cout << bob;
		try {
			bob.incrementGrade();
		}
		catch(const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << bob;
	
		try {
			bob.incrementGrade();
		}
		catch(const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << bob;

		std::cout << "\nTest decreasing:\n" << std::endl;
		Bureaucrat tim("Tim", 149);
		std::cout << tim;
		try {
			tim.decrementGrade();
		}
		catch(const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << tim;

		try {
			tim.decrementGrade();
		}
		catch(const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << tim;
		std::cout << "\n";
	}

	std::cout << std::endl << "Test ex03\n" << std::endl;

	Intern	intern;
		std::cout << std::endl;
	try {
		std::cout << "ShrubberyCreationForm\n" << std::endl;
		Bureaucrat Mr_Shrubby("Mr_Shrubby", 130);
		std::cout << std::endl;
		AForm&	Shrubby_form = *intern.makeForm("ShrubberyCreationForm", "Forest");
		std::cout << std::endl;
		Mr_Shrubby.signForm(Shrubby_form);
		std::cout << std::endl;
		std::cout << Shrubby_form;
		std::cout << std::endl;
		Mr_Shrubby.executeForm(Shrubby_form);
		delete(&Shrubby_form);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	try {
		std::cout << std::endl << "RobotomyRequestForm\n" << std::endl;
		Bureaucrat Mr_Robo("Mr_Robo", 45);
		std::cout << std::endl;
		AForm&	Robo_form = *intern.makeForm("RobotomyRequestForm", "ClapTrap");
		std::cout << std::endl;
		Mr_Robo.executeForm(Robo_form);
		std::cout << std::endl;
		Mr_Robo.signForm(Robo_form);
		std::cout << std::endl;
		Mr_Robo.executeForm(Robo_form);
		std::cout << std::endl;
		Mr_Robo.executeForm(Robo_form);
		std::cout << std::endl;
		Mr_Robo.executeForm(Robo_form);
		std::cout << std::endl;
		delete(&Robo_form);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "PresidentialPardonForm\n" << std::endl;
		Bureaucrat Mr_Robo("Mr_Robo", 45);
		std::cout << std::endl;
		Bureaucrat Mr_President("Mr_President", 5);
		std::cout << std::endl;
		AForm&	President_form = *intern.makeForm("PresidentialPardonForm", "ClapTrap");
		std::cout << std::endl;
		Mr_Robo.executeForm(President_form);
		std::cout << std::endl;
		Mr_Robo.signForm(President_form);
		std::cout << std::endl;
		Mr_President.executeForm(President_form);
		std::cout << std::endl;
		Mr_President.signForm(President_form);
		std::cout << std::endl;
		Mr_President.executeForm(President_form);
		std::cout << std::endl;
		delete(&President_form);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		std::cout << "Random form\n" << std::endl;
		AForm& Some_form = *intern.makeForm("Genericform", "ClapTrap");
		Bureaucrat Mr_President("Mr_President", 5);
		std::cout << std::endl;
		Mr_President.executeForm(Some_form);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
