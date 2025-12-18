/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 09:55:16 by stempels          #+#    #+#             */
/*   Updated: 2025/12/12 10:05:52 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCALARCONVERTER_HPP
# define	SCALARCONVERTER_HPP

/*Includes*/
# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>

class	ScalarConverter {
	public:
	/*Public Method*/
		static void	convert(const std::string literal) ;

	private:
	/*Constructor - Copy Constructor - Destructor*/
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy_from);
		~ScalarConverter();

	/*Overloaded Operator*/
		ScalarConverter&	operator=(const ScalarConverter& other);
};

#endif
