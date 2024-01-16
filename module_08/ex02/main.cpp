/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:47:28 by jaurasma          #+#    #+#             */
/*   Updated: 2023/12/11 13:37:43 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main() {
    {
        std::cout << "Using MutantStack (42 example test)" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
        std::cout << "---------------" << std::endl;
    }
    {
        std::cout << "Using list (should be indentical to 42 test example)" << std::endl;
        std::list<int> list;
        list.push_back(5);
        list.push_back(17);
        std::cout << "top: " << list.back() << std::endl;
        list.pop_back();
        std::cout << "size: " << list.size() << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::list<int> s(list);
        std::cout << "---------------" << std::endl;
    }
    {
        std::cout << "Using MutantStack with double" << std::endl;
        MutantStack<double> mstack;
        mstack.push(3.14);
        mstack.push(2.718);
        std::cout << "top: " << mstack.top() << std::endl;
        std::cout << "size: " << mstack.size() << std::endl;
        mstack.pop();
        std::cout << "size after pop: " << mstack.size() << std::endl;
        mstack.push(1.234);
        mstack.push(5.678);
        MutantStack<double>::iterator it = mstack.begin();
        MutantStack<double>::iterator ite = mstack.end();
        std::cout << "iterator in mutantstack:" << std::endl;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        //create a standard stack from the mutantstack
        std::stack<double> s(mstack);
        std::cout << "Standard stack elements:" << std::endl;
        while (!s.empty()) {
            std::cout << s.top() << std::endl;
            s.pop();
        }
    }

    return 0;
}