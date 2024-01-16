/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:47:28 by jaurasma          #+#    #+#             */
/*   Updated: 2023/12/08 16:04:56 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
// #include <string>
#include <exception>

int main(){
    try{
    Span sp = Span(15000);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(12);
    sp.addNumbers(14993);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;}
    catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    return (0);
}
