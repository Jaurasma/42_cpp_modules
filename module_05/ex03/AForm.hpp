/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:29:00 by jaurasma          #+#    #+#             */
/*   Updated: 2023/10/27 15:56:45 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration of Bureaucrat class
class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeRequiredToSign;
        const int           _gradeRequiredToExecute;

    public:
        AForm();
        AForm(const std::string& name, int gradeSign, int gradeExecute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeRequiredToSign() const;
        int getGradeRequiredToExecute() const;
        void beSigned(Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor)const;
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, AForm& form);

#endif
