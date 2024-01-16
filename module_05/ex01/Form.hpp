/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:29:00 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/27 16:20:59 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeRequiredToSign;
        const int           _gradeRequiredToExecute;

    public:
        Form();
        Form(const std::string& name, int gradeSign, int gradeExecute);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeRequiredToSign() const;
        int getGradeRequiredToExecute() const;
        void beSigned(Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, Form& form);

#endif
