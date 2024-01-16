/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:24:31 by jaurasma          #+#    #+#             */
/*   Updated: 2023/12/05 13:33:24 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T> class Array {
    private:
        T* _elements;
        unsigned int _arraySize;
        Array(void);
    public:
        Array(unsigned int n);
        ~Array(void);
        Array(const Array& copy);
        Array &operator=(const Array& copy);
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
        
        class IndexOutOfBounds : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif