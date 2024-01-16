/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:41:54 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/23 13:55:17 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, std::size_t length, void (*func)(T&)) {
    for (std::size_t i = 0; i < length; i++) {
        func(array[i]);
    }
};

template <typename T>
void iter(T *array, std::size_t length, void (*func)(const T&)) {
    for (std::size_t i = 0; i < length; i++) {
        func(array[i]);
    }
};

template <typename T>
void printElement(const T& element) {
    std::cout << element << " " << std::endl;
}

template <typename T>
void squareElement(T& element) {
    element *= element;
}

#endif