/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 07:40:00 by stempels          #+#    #+#             */
/*   Updated: 2025/11/24 08:29:12 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	std::cout << "\nTest ex00\n" << std::endl;

	std::cout << "Highest grade possible: " << HIGHEST_GRADE << std::endl;
	std::cout << "Lowest grade possible: " << LOWEST_GRADE << std::endl;

	std::cout << "\nTest too high and too low creation" << std::endl;
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

	std::cout << "\nTest increasing\n" << std::endl;
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



	std::cout << "\nTest decreasing\n" << std::endl;
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
	
	return (0);
}
