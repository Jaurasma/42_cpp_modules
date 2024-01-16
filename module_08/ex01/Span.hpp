/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:47:25 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/23 18:54:01 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _data;
        Span(void);
    public:
        Span(unsigned int N);
        ~Span(void);
        Span(const Span& copy);
        Span &operator=(const Span& copy);
        void addNumber(int num);
        void addNumbers(int amount);
        int shortestSpan(void);
        int longestSpan(void);
        class ContainerFull : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class NoSpan : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class ContainerWillBeTooFull : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif