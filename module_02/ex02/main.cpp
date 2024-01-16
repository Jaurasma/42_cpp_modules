/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:43:16 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/28 14:37:52 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}


/*better test main*/
// int main() {
//     // Create fixed-point numbers
//     Fixed a(2.5f);
//     Fixed b(4.75f);
//     Fixed c = a;

//     std::cout << "a is " << a << " and b is " << b << " and c is " << c << std::endl;
//     // Test comparison operators
//     std::cout << "a > b: " << (a > b) << std::endl;
//     std::cout << "a < b: " << (a < b) << std::endl;
//     std::cout << "a >= c: " << (a >= c) << std::endl;
//     std::cout << "a <= c: " << (a <= c) << std::endl;
//     std::cout << "a == c: " << (a == c) << std::endl;
//     std::cout << "a != b: " << (a != b) << std::endl;

//     // Test arithmetic operators
//     std::cout << "a + b: " << (a + b) << std::endl;
//     std::cout << "b - a: " << (b - a) << std::endl;
//     std::cout << "a * b: " << (a * b) << std::endl;
//     std::cout << "b / a: " << (b / a) << std::endl;

//     // Test increment/decrement operators
//     std::cout << "a++: " << a++ << std::endl;
//     std::cout << "++a: " << ++a << std::endl;
//     std::cout << "--b: " << --b << std::endl;
//     std::cout << "b--: " << b-- << std::endl;

//     // Test min and max static member functions
//     Fixed &smaller = Fixed::min(a, b);
//     const Fixed &smallerConst = Fixed::min(a, b);
//     Fixed &larger = Fixed::max(a, b);
//     const Fixed &largerConst = Fixed::max(a, b);

//     std::cout << "Smaller (non-const): " << smaller << std::endl;
//     std::cout << "Smaller (const): " << smallerConst << std::endl;
//     std::cout << "Larger (non-const): " << larger << std::endl;
//     std::cout << "Larger (const): " << largerConst << std::endl;

//     return 0;
// }
