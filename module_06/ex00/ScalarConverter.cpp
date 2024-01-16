/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:37:03 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/21 15:45:09 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	// std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy){
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	// std::cout << "ScalarConverter destructor called" << std::endl;
}

static bool isChar(const std::string &input){
	if (input.length() > 1 || input[0] < 32 || (input[0] > 46 && input[0] < 59) || input[0] > 126) {
		return false;
	}
	return true;
}

static bool isInt(const std::string& input) {
	std::istringstream ss(input);
	int value;
	ss >> value;
	return !ss.fail() && ss.eof();
}

static bool isFloat(const std::string& input) {
	if (input == "inff" || input == "-inff" || input == "+inff" || input == "nanf")
		return true;
	if (input.back() == 'f') {
		std::istringstream ss(input.substr(0, input.length() - 1));
		float value;
		ss >> value;
		return !ss.fail() && ss.eof();
	}
	return false;
}

static bool isDouble(const std::string& input) {
	if (input == "inf" || input == "-inf" || input == "+inf" || input == "nan")
		return true;
	if (input.back() != 'f') {
		std::istringstream ss(input);
		double value;
		ss >> value;
		return !ss.fail() && ss.eof();
	}
	return false;
}

static int extractType(const std::string &input) {
	if (isChar(input)) {
		std::cout << "Input is a char.\n" << std::endl;
		return 1;
	} else if (isInt(input)) {
		std::cout << "Input is an int.\n" << std::endl;
		return 2;
	} else if (isFloat(input)) {
		std::cout << "Input is a float.\n" << std::endl;
		return 3;
	} else if (isDouble(input)) {
		std::cout << "Input is a double.\n" << std::endl;
		return 4;
	} else {
		std::cerr << "Input is none of the supported types.\n" << std::endl;
		return -1;
	}

	return 0;
}

static bool isCharShowable(char c)
{
	if (c < 33)
		return false;
	if (c > 47 && c < 58)
		return false;
	if (c == 127)
		return false;
	return true;
}

void ScalarConverter::convert(const std::string &input) {
	int status = extractType(input);
	char c;
	int intValue = 0;
	double floatValue = 0;
	float doubleValue = 0;
	
	if (status == -1) {
		std::cout << "Type conversion is impossible, allowed types are char, int, float, and double!" << std::endl;
	} else if (status == 1) {
		c = input[0];
		intValue = static_cast<int>(c);
		floatValue = static_cast<float>(c);
		doubleValue = static_cast<double>(c);
	} else if (status == 2) {
		intValue = std::stoi(input);
		c = static_cast<char>(intValue);
		floatValue = static_cast<float>(intValue);
		doubleValue = static_cast<double>(intValue);
	} else if (status == 3) {
		floatValue = std::stof(input);
		c = static_cast<char>(floatValue);
		intValue = static_cast<int>(floatValue);
		doubleValue = static_cast<double>(floatValue);
	} else if (status == 4) {
		doubleValue = std::stod(input);
		c = static_cast<char>(doubleValue);
		intValue = static_cast<int>(doubleValue);
		floatValue = static_cast<float>(doubleValue);
	}
    std::cout << "Char: ";
    if (status < 1 || doubleValue > 127 || doubleValue < 0 || isnan(doubleValue)) {
        std::cout << "impossible" << std::endl;
    } else if (isCharShowable(c)) {
        std::cout << "'" << c << "'" << std::endl;
    } else {
        std::cout << "not displayable" << std::endl;
    }
    std::cout << "Int: ";
    if (status > 0 && status < 4 && !isnan(doubleValue) && !isinf(doubleValue) &&
        (doubleValue > std::numeric_limits<int>::min() && doubleValue < std::numeric_limits<int>::max())) {
        std::cout << intValue << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "Float: ";
    if (status > 0) {
        std::cout << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "Double: ";
    if (status > 0) {
        std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }
}

