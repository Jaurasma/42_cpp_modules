/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:29:00 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/31 14:32:56 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("Presidential Pardon Form", 25, 5), _target("Default target") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm for " << this->_target <<  " constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    : AForm(copy) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    if (this != &copy) {
        AForm::operator=(copy);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getGradeRequiredToExecute()) {
        throw (Bureaucrat::GradeTooLowException());
        return ;
    }
    else if ( this->getIsSigned() != true) {
        throw (Bureaucrat::formNotSignedException());
        return ;
    }
    std::cout << this->_target + " has been pardoned by Zaphod Beeblebrox." << std::endl;
}