/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:37:03 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/31 14:22:16 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat default costurcor called" << std::endl;
	this->_grade = 0;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	std::cout << "Bureaucrat overload costurcor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	_grade = copy._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	_grade = copy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	// std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() {
	return (this->_name);
}

int Bureaucrat::getGrade() {
	return (this->_grade);
}

void    Bureaucrat::incrementGrade() {
	if (this->_grade > 1)
		this->_grade--;
	else
		throw GradeTooHighException();
}

void    Bureaucrat::decrementGrade() {
    if (this->_grade < 150)
        this->_grade++;
    else
        throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}