/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:29:00 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/31 14:45:08 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {
    std::cout << "Intern default constuctor called" << std::endl;
}

Intern::Intern(const Intern& copy) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    if (this != &copy) {
        Intern::operator=(copy);
    }
    return *this;
}

Intern::~Intern() {
    // std::cout << "Intern destructor called" << std::endl;
}

static AForm* robotomyCreate(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* shrubberyCreate(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* presidentialCreate(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    static const std::string forms[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    static AForm* (*functions[])(const std::string&) = {robotomyCreate, shrubberyCreate, presidentialCreate};

    for (size_t i = 0; i < 3; i++) {
        if (formName == forms[i]) {
            std::cout << "Intern creates " << formName << " form" << std::endl;
            return functions[i](target);
        }
    }

    std::cout << "Error: Unknown form name " << formName << std::endl;
    return NULL;
}
