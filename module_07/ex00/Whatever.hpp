/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:41:54 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/20 13:50:47 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
};

template <typename T>
T min(const T &a, const T &b) {
    return (a < b) ? a : b;
};

template <typename T>
T max(const T &a, const T &b) {
    return (a > b) ? a : b;
};

#endif