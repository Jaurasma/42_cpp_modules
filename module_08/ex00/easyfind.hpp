/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:20:00 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/21 16:38:28 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

template <typename T>
void easyfind(T container, int value) {
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if (iter != container.end())
        std::cout << "int " << value <<" found in the container" << std::endl;
    else
        throw std::out_of_range("Value not found in container");
}

#endif