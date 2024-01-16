/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:29:00 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/25 15:37:46 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Shrubbery Creation Form", 145, 137), _target("Default target") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm for " + this->_target +  " constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    : AForm(copy) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    if (this != &copy) {
        AForm::operator=(copy);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getGradeRequiredToExecute()) {
        throw (Bureaucrat::GradeTooLowException());
        return ;
    }
    else if ( this->getIsSigned() != true) {
        throw (Bureaucrat::formNotSignedException());
        return ;
    }
    std::ofstream outFile(getTarget() + "_shrubbery");
    if (outFile.is_open()) {
        for (int i = 0; i < 5; i++){
            outFile << "    v    " << std::endl;
            outFile << "   vvv   " << std::endl;
            outFile << "  vvvvv  " << std::endl;
            outFile << " vvvvvvv " << std::endl;
            outFile << "vvvvvvvvv" << std::endl;
            outFile << "   | |   " << std::endl;
            outFile << "  /   \\ " << std::endl;
            outFile << "" << std::endl;
        }
        outFile.close();
        std::cout << "Shrubbery created and saved to " << getTarget() + "_shrubbery" << std::endl;
    } else {
        std::cout << "ShrubberyCreationForm execution failed: Unable to create the file." << std::endl;
    }
}