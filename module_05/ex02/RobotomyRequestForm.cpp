/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:29:00 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/31 14:34:06 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("Robotom yRequest Form", 72, 45), _target("Default target") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm for " << this->_target << " constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    : AForm(copy) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    if (this != &copy) {
        AForm::operator=(copy);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getGradeRequiredToExecute()) {
        throw (Bureaucrat::GradeTooLowException());
        return ;
    }
    else if ( this->getIsSigned() != true) {
        throw (Bureaucrat::formNotSignedException());
        return ;
    }
    srand(static_cast<unsigned int>(time(NULL)));
    std::cout << "Robot drilling noises *beeb boob vroom vroom*" << std::endl;
    if (rand() % 2 != 0) {
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    }
    else {
        std::cout << "Sad beeb boob robotomy failed." << std::endl;
    }
}