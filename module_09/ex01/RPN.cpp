/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:51:37 by jaurasma          #+#    #+#             */
/*   Updated: 2024/01/10 14:20:42 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(RPN& copy) {
    this->_operandStack = copy._operandStack;
}

RPN& RPN::operator=(RPN &copy){
    if (this != &copy)
        this->_operandStack = copy._operandStack;
    return *this;
}

bool RPN::isOperator(const std::string& token){
    if (token == "+" || token == "-" || token == "/" || token == "*")
        return true;
    return false;
}

int RPN::perfromRPN(char op, int operand1, int operand2){
    switch (op)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '/':
        if (operand2 != 0) {
            return operand1 / operand2;
        } else {
            std::cout << "Error: Division by zero." << std::endl;
            exit(EXIT_FAILURE);
        }   
    case '*':
        return operand1 * operand2;
    default:
        std::cout << "Error: Unknown operator." << std::endl;
        exit(EXIT_FAILURE);
    }
}

int RPN::evaluateRPN(const std::string& expression){

    std::istringstream iss(expression);
    std::string token;
    int operand1;
    int operand2;
    int result;
    double number;
    
    while (iss >> token) {
        if ((isdigit(token[0])) || (token.length() > 1 && token[0] == '-' && isdigit(token[1]))) {
            number = std::stod(token);
            if (std::abs(number) >= 10 || std::floor(number) != number) {
                std::cout << "Error: Numbers must between -9 - 9 and not decimal number" << std::endl;
                exit(EXIT_FAILURE);
            }
            _operandStack.push(static_cast<int>(number));
        } else if (isOperator(token)) {
            if (_operandStack.size() < 2) {
                std::cout << "Error: Not enough expressions" << std::endl;
                exit(EXIT_FAILURE);
            }
            operand2 = _operandStack.top();
            _operandStack.pop();
            operand1 = _operandStack.top();
            _operandStack.pop();
            result = perfromRPN(token[0], operand1, operand2);
            _operandStack.push(result);
        } else {
            std::cout << "Error: invalid characters" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    if (_operandStack.size() != 1) {
        std::cout << "Error: Invalid expression" << std::endl;
        exit(EXIT_FAILURE);
    }

    return _operandStack.top();
}
