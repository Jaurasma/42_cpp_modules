/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:51:34 by jaurasma          #+#    #+#             */
/*   Updated: 2023/12/14 14:45:50 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cmath>

class RPN {
    private:
        RPN(RPN &copy);
        RPN& operator=(RPN &copy);
        std::stack<int> _operandStack;
    public:
        RPN(void);
        ~RPN(void);
        int evaluateRPN(const std::string& expression);
        int perfromRPN(char op, int operand1, int operand2);
        bool isOperator(const std::string& token);
};

#endif