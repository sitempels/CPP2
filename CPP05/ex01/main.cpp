/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 07:40:00 by stempels          #+#    #+#             */
/*   Updated: 2025/11/28 09:33:36 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	std::cout << "\nTest ex00\n" << std::endl;
/*	std::cout << "\nClass test\n" << std::endl;
	Bureaucrat	test1("Timothe", 2);
	{
		Bureaucrat	test2;
		test2 = test1;
		Bureaucrat	test3(test1);
		
	}
	std::cout << test1;
*/
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

	std::cout << std::endl << "Test ex01\n" << std::endl;

	try {
		Form ex1_form("EXEMPLE1 FORM", 100, 0);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		Form ex2_form("EXEMPLE2 FORM", 151, 1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	Form id_form("ID FORM", 100, 90);
	std::cout << std::endl;
	Bureaucrat mr_slow;
	std::cout << std::endl;
	Bureaucrat mr_id("MR_ID", 100);
	std::cout << std::endl;
	std::cout << id_form;
	std::cout << std::endl;
	mr_slow.signForm(id_form);
	std::cout << std::endl;
	std::cout << id_form;
	std::cout << std::endl;
	mr_id.signForm(id_form);
	std::cout << std::endl;
	std::cout << id_form;
	std::cout << std::endl;
	
	return (0);
}
