/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:29:15 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/31 15:47:51 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default Form"), _isSigned(false), _gradeRequiredToSign(0), _gradeRequiredToExecute(0) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeSign, int gradeExecute) 
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeSign), _gradeRequiredToExecute(gradeExecute) {
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeRequiredToSign(other._gradeRequiredToSign),
      _gradeRequiredToExecute(other._gradeRequiredToExecute) {
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		return *this;
	}
	return *this;
}

Form::~Form() {
	// std::cout << "Form destructor called" << std::endl;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= getGradeRequiredToSign())
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const std::string& Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

int Form::getGradeRequiredToSign() const {
	return _gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
	return _gradeRequiredToExecute;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, Form& form) {
	os << "Form Name: " << form.getName() << std::endl;
	os << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	os << "Grade Required to Sign: " << form.getGradeRequiredToSign() << std::endl;
	os << "Grade Required to Execute: " << form.getGradeRequiredToExecute() << std::endl;
	return os;
}
