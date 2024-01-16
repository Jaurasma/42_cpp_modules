/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:06:57 by jaurasma          #+#    #+#             */
/*   Updated: 2024/01/10 13:53:19 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

int main() {
    int intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const std::string stringArray[] = {"hello", "I'm", "test", "array"};
    // test with int array
    std::cout << "testing with int array"<<std::endl;
    iter(intArray, sizeof(intArray) / sizeof(intArray[0]), printElement<int>);
    iter(intArray, sizeof(intArray) / sizeof(intArray[0]), squareElement<int>);
    std::cout << "squared int array"<<std::endl;
    iter(intArray, sizeof(intArray) / sizeof(intArray[0]), printElement<int>);
    // test with char array
    std::cout << "testing with const char array"<<std::endl;
    iter(stringArray, sizeof(stringArray) / sizeof(stringArray[0]), printElement<std::string>);
    return (0); 
}
