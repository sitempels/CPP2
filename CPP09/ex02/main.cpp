/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:50:36 by stempels          #+#    #+#             */
/*   Updated: 2026/02/02 13:53:09 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pMergeMe.hpp"
#include <ctime>
#include <sys/time.h>

static long int	getTime() ;

int	main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error: one argument needed" << std::endl;
		return (1);
	}
	if (!fordJohnson::isValidInput(argv)) {
		std::cerr << "Error: invalid argument" << std::endl;
		return (1);
	}
	{
		std::cout << "------   VECTOR container   -----\n" << std::endl;
		std::vector<unsigned int>	container = fordJohnson::fillVectContainer(argv);
		std::cout << "Before:\t";
		for (std::vector<unsigned int>::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << ' ';
		}
		long int	 start_time = getTime();
		std::cout << std::endl;
		if (!fordJohnson::runAlgo(container))
			return (1);
		long int	process_time = getTime() - start_time;
		std::cout << "After:\t";
		for (std::vector<unsigned int>::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
		std::cout << "Time to process a range of " << container.size() << " elements with std::vector: " << process_time << " usec" << std::endl;
		std::cout << "Comparaisons made: " << fordJohnson::g_comp << std::endl;
		std::cout << "\n---------------------------------" << std::endl;
	}
	return (0);
}

static long int	getTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000L + tv.tv_usec);
}
