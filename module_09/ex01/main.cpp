/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:14:00 by jaurasma          #+#    #+#             */
/*   Updated: 2024/01/10 14:22:44 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./RPN \"<RPN_expression>\"" << std::endl;
        return EXIT_FAILURE;
    }
    std::string expression = argv[1];
    RPN rpn;
    try {
        int result = rpn.evaluateRPN(expression);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}