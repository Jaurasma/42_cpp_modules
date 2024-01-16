/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:36:32 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/21 15:45:22 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a value: ";
    
    std::string userInput;
    std::getline(std::cin, userInput);

    ScalarConverter::convert(userInput);

    return 0;
}
