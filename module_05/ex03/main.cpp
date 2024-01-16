/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:36:32 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/31 15:56:24 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Bureaucrat *BureacratJohn = new Bureaucrat("John", 40);
    Intern someRandomIntern;
    AForm* forms[4];
    
    std::cout << "|-----------ROBO-----------|" << std::endl;
    forms[0] = someRandomIntern.makeForm("robotomy request", "ROBO");
    std::cout << "|-----------SHRUB----------------|" << std::endl;
    forms[1] = someRandomIntern.makeForm("shrubbery creation", "SHRUB");
    std::cout << "|-----------PRES-----------------|" << std::endl;
    forms[2] = someRandomIntern.makeForm("presidential pardon", "PRES");
    std::cout << "|-----------BROKEN---------------|" << std::endl;
    forms[3] = someRandomIntern.makeForm("blackhole extension form", "BROKEN");
    std::cout << "|-----------FORM TESTS-----------|" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "|-----------round " << i << "-----------|" << std::endl;
        if (forms[i] != NULL) {
            try {
                BureacratJohn->signForm(*forms[i]);
                BureacratJohn->executeForm(*forms[i]);
            }
            catch (const std::exception& e) {
                std::cout << "Exception: " << e.what() << std::endl;
            }
            delete forms[i];
        }
    }

    delete BureacratJohn;
}