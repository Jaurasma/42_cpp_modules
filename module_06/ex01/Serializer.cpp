/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:36:51 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/17 14:32:33 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

    Serializer::Serializer(){
        std::cout << "Serializer constructor called" << std::endl;
    }
    
    Serializer::~Serializer(){
        std::cout << "Serializer destructor called" << std::endl;
    }

    Serializer::Serializer(const Serializer& copy){
        *this = copy;
    }

    Serializer& Serializer::operator=(const Serializer& copy){
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &copy)
            return (*this);
        return (*this);
    }

    uintptr_t  Serializer::serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    Data*  Serializer::deserialize(uintptr_t raw){
        return reinterpret_cast<Data*>(raw);
    }