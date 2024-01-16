/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:42:27 by jaurasma          #+#    #+#             */
/*   Updated: 2024/01/10 14:22:50 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv){
    BitcoinExchange btc;

    if (argc != 2) {
        std::cout << "Error: could not open file" << std::endl;
        return EXIT_FAILURE;
    }
    try {
        btc.extractDatabase();
        btc.processInput(argv[1]);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}