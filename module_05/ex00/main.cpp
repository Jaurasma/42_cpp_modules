/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:36:32 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/31 14:23:14 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main() {
    try {
        Bureaucrat highGradeBureaucrat("Alice", 2);
        Bureaucrat lowGradeBureaucrat("Bob", 130);

        highGradeBureaucrat.incrementGrade();
        lowGradeBureaucrat.decrementGrade();

        std::cout << highGradeBureaucrat << std::endl;
        std::cout << lowGradeBureaucrat << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
