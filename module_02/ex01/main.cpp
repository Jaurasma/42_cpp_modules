/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:43:16 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/28 14:37:02 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}


/*secondary test*/
// int main() {
//     // Test Int constructor
//     Fixed a(42);
//     std::cout << "a: " << a << " (as float: " << a.toFloat() << ")" << std::endl;

//     // Test Float constructor
//     Fixed b(3.14f);
//     std::cout << "b: " << b << " (as int: " << b.toInt() << ")" << std::endl;

//     // Test Copy constructor
//     Fixed c(b);
//     std::cout << "c: " << c << std::endl;

//     // Test Copy assignment operator
//     Fixed d;
//     d = a;
//     std::cout << "d: " << d << std::endl;

//     return 0;
// }
