/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:43:41 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/28 14:59:18 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractionalBits;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& copy);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& fixed);

#endif
