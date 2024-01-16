/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:19:53 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/21 17:10:34 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

int main() {
    try {
        std::cout << "Enter a value to find from the container: ";
        std::string userInput;
        std::getline(std::cin, userInput);
        int userValue = std::stoi(userInput);
        std::vector<int> vec;
        for (int i = 0; i < 10000; i++)
            vec.push_back(i);
        easyfind(vec, userValue);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}