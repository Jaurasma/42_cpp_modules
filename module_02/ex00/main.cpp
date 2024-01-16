/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:43:16 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/28 14:40:42 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

/*better test main*/
// int main() {
//     // Test Default constructor
//     Fixed a;

//     // Test Copy constructor
//     Fixed b(a);

//     // Test Copy assignment operator
//     Fixed c;
//     c = b;

// 	//original test
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;
	
//     // Test getRawBits and setRawBits
//     int rawValue = 123;
//     c.setRawBits(rawValue);
//     std::cout << "c.getRawBits(): " << c.getRawBits() << std::endl;

//     return 0;
// }