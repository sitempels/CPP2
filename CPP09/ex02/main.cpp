/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:50:36 by stempels          #+#    #+#             */
/*   Updated: 2026/02/09 14:49:25 by stempels         ###   ########.fr       */
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
		long int	 start_time = getTime();
		std::vector<unsigned int>	container = fordJohnson::fillVectContainer(argv);
		long int	process_time = getTime() - start_time;
		std::cout << "\nBefore:\t";
		int i = 0;
		std::vector<unsigned int>::const_iterator it = container.begin();
		while (it != container.end()) {
			if (i > 10) {
				std::cout << "[...]";
				break ;
			}
			else
				std::cout << *it << ' ';
			it++;
			i++;
		}
		std::cout << std::endl;
		start_time = getTime();
		if (!fordJohnson::runAlgo(container))
			return (1);
		process_time = getTime() - start_time;
		i = 0;
		it = container.begin();
		std::cout << "\nAfter:\t";
		while (it != container.end()) {
			if (i > 10) {
				std::cout << "[...]";
				break ;
			}
			else
				std::cout << *it << ' ';
			it++;
			i++;
		}
		std::cout << std::endl;
		std::cout << "\n------   VECTOR container   -----\n" << std::endl;
		std::cout << "Time to fill a range of " << container.size() << " elements with std::vector: " << process_time << " usec" << std::endl;
		std::cout << "Time to process a range of " << container.size() << " elements with std::vector: " << process_time << " usec" << std::endl;
		std::cout << "Comparaisons made: " << fordJohnson::g_comp << std::endl;
		std::vector<unsigned int>::const_iterator	cit = container.begin();
		unsigned int prev = *cit;
		while (cit != container.end()) {
			if (prev > *cit)
				break ;
			prev = *cit;
			cit++;
		}
		if (cit == container.end())
			std::cout << "Container is ordered." << std::endl;
		else
			std::cerr << "Error: container isn't ordered." << std::endl;

	//	std::cout << "---------------------------------" << std::endl;
	}
	fordJohnson::g_comp = 0;
	{
		std::cout << "\n------   DEQUE container   -----\n" << std::endl;
		long int	 start_time = getTime();
		std::deque<unsigned int>	container = fordJohnson::fillDeqContainer(argv);
		long int	process_time = getTime() - start_time;
		std::cout << "Time to fill a range of " << container.size() << " elements with std::deque: " << process_time << " usec" << std::endl;
		start_time = getTime();
		if (!fordJohnson::runAlgo(container))
			return (1);
		process_time = getTime() - start_time;
		std::cout << "Time to process a range of " << container.size() << " elements with std::deque: " << process_time << " usec" << std::endl;
		std::cout << "Comparaisons made: " << fordJohnson::g_comp << std::endl;
		std::deque<unsigned int>::const_iterator	cit = container.begin();
		unsigned int prev = *cit;
		while (cit != container.end()) {
			if (prev > *cit)
				break ;
			prev = *cit;
			cit++;
		}
		if (cit == container.end())
			std::cout << "Container is ordered." << std::endl;
		else
			std::cerr << "Error: container isn't ordered." << std::endl;

		std::cout << "---------------------------------" << std::endl;
	}
	return (0);
}

static long int	getTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000L + tv.tv_usec);
}
