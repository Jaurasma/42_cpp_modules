/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:56:55 by jaurasma          #+#    #+#             */
/*   Updated: 2023/12/11 13:25:01 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() : std::stack<T>() {}

    ~MutantStack() {}

    MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}

    MutantStack& operator=(const MutantStack& copy) {
        if (this != &copy) {
            std::stack<T>::operator=(copy);
        }
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() {
        return std::stack<T>::c.begin();
    }

    iterator end() {
        return std::stack<T>::c.end();
    }

    const_iterator begin() const {
        return std::stack<T>::c.begin();
    }

    const_iterator end() const {
        return std::stack<T>::c.end();
    }
};

#endif
