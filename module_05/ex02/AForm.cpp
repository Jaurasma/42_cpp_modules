/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:29:15 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/31 15:45:52 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default Form"), _isSigned(false), _gradeRequiredToSign(0), _gradeRequiredToExecute(0) {
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute) 
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeSign), _gradeRequiredToExecute(gradeExecute) {
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeRequiredToSign(other._gradeRequiredToSign),
      _gradeRequiredToExecute(other._gradeRequiredToExecute) {
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		return *this;
	}
	return *this;
}

AForm::~AForm() {
	// std::cout << "AFrom destructor called" << std::endl;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= getGradeRequiredToSign())
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const std::string& AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

int AForm::getGradeRequiredToSign() const {
	return _gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
	return _gradeRequiredToExecute;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

void AForm::execute(Bureaucrat const & executor) const{
	(void)executor;
}

std::ostream& operator<<(std::ostream& os, AForm& form) {
	os << "Form Name: " << form.getName() << std::endl;
	os << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	os << "Grade Required to Sign: " << form.getGradeRequiredToSign() << std::endl;
	os << "Grade Required to Execute: " << form.getGradeRequiredToExecute() << std::endl;
	return os;
}
