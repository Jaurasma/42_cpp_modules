/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:36:32 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/31 14:23:17 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int main() {
    try {
        Bureaucrat bureaucrat("John", 20);
        Form form("Tax Form", 40, 30);

        // Attempt to sign the form by the bureaucrat
        bureaucrat.signForm(form);

        // Print form information using the overloaded operator<<
        std::cout << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}