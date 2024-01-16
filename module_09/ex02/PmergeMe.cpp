/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:46:07 by jaurasma          #+#    #+#             */
/*   Updated: 2024/01/10 14:23:29 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
    : _listTime(0), _vectorTime(0), _containerSize(0){
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe &copy) {
    _containerSize = copy._containerSize;
    _vectorSequence = copy._vectorSequence;
    _listSequence = copy._listSequence;
    _printSequence = copy._printSequence;
    _vectorTime = copy._vectorTime;
    _listTime = copy._listTime;
}

PmergeMe& PmergeMe::operator=(PmergeMe &copy){
    if (this != &copy)
        _containerSize = copy._containerSize;
        _vectorSequence = copy._vectorSequence;
        _listSequence = copy._listSequence;
        _printSequence = copy._printSequence;
        _vectorTime = copy._vectorTime;
        _listTime = copy._listTime;
    return *this;
}

void PmergeMe::timePrinter(std::string type, clock_t endTime) {
    std::cout << "Time to process a range of " << _containerSize << " elements with std::" << type << " : "<< endTime << " μs" << std::endl;
}

void PmergeMe::sort(int argc, char **argv) {
    
    _listTime = runSorting(_listSequence, argv, argc);
    if (_listTime == 0) return ;
    _vectorTime =  runSorting(_vectorSequence, argv, argc);
    if (_vectorTime == 0) return ;
    _containerSize = printNumbers(_printSequence, argv, argc);
    timePrinter("list", _listTime);
    timePrinter("vector", _vectorTime);
    return ;
}
