/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:36:32 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/31 15:31:44 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "|-----ShrubberyCreationForm-----|" << std::endl;
    Bureaucrat *BureacratJohn = new Bureaucrat("John", 130);
    AForm *fromShrub = new ShrubberyCreationForm("PUSKA");
    try {
        BureacratJohn->signForm(*fromShrub);
        BureacratJohn->executeForm(*fromShrub);
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    delete BureacratJohn;
    delete fromShrub;
    std::cout << "|-----RobotomyRequestForm-----|" << std::endl;
    Bureaucrat *BureacratTom = new Bureaucrat("Tom", 44);
    AForm *fromRobo = new RobotomyRequestForm("ROBOCOP");
    try {
        BureacratTom->signForm(*fromRobo);
        BureacratTom->executeForm(*fromRobo);
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    delete BureacratTom;
    delete fromRobo;
    std::cout << "|-----PresidentialPardonForm-----|" << std::endl;

    Bureaucrat *BureacratJim = new Bureaucrat("Jim", 4);
    AForm *fromPres = new PresidentialPardonForm("Arthur Dent");
    try {
        BureacratTom->signForm(*fromPres);
        BureacratTom->executeForm(*fromPres);
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    delete BureacratJim;
    delete fromPres;
    return 0;
}