/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:36:51 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/21 15:45:14 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

class ScalarConverter {
	private:
			ScalarConverter();
			ScalarConverter(const ScalarConverter& copy);
			ScalarConverter &operator=(const ScalarConverter& copy);
			~ScalarConverter(void);
	public:
			static void convert(const std::string &input);
};

#endif
