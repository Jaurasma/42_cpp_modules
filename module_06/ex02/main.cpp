/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:36:51 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/21 15:44:17 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base * generate(void) {
    int randomValue = rand() % 3;
    switch (randomValue) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL){
        std::cout << "ptr is A" << std::endl;
    }
    else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "ptr is B" << std::endl;
    }
    else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "ptr is C" << std::endl;
    }
    else {
        std::cout << "error" << std::endl; 
    }
}

void identify(Base& p) {
    A a;
    B b;
    C c;
    try {
        a = dynamic_cast<A&>(p);
        std::cout << "ref is A" << std::endl;
    } catch (std::exception& e){
    }
    try {
        b = dynamic_cast<B&>(p);
        std::cout << "ref is B" << std::endl;
    } catch (std::exception& e){
    }
    try {
        c = dynamic_cast<C&>(p);
        std::cout << "ref is C" << std::endl;
    } catch (std::exception& e){
    }
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    Base *randomObject = generate();
    
    if (randomObject != NULL) {
        identify(randomObject);
        identify(*randomObject);
        delete randomObject;
    } else {
        std::cout << "it was a null prt wtf?????" << std::endl;
    }
    return 0;
}