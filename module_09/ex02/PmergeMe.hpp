/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:46:04 by jaurasma          #+#    #+#             */
/*   Updated: 2024/01/10 14:24:42 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>

class PmergeMe {
    private:
        clock_t             _listTime;
        clock_t             _vectorTime;
        int                 _containerSize;
        std::vector<int>    _vectorSequence;
        std::list<int>      _listSequence;
        std::vector<int>    _printSequence;
    public:
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(PmergeMe &copy);
        PmergeMe& operator=(PmergeMe &copy);
        void timePrinter(std::string type, clock_t endTime);
        void sort(int argc, char **argv);
};

template <typename T>
long long getCurrentTimeMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<double>(tv.tv_sec) * 1000000 + tv.tv_usec;
}

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end) {
    for (Iterator i = begin; i != end; ++i) {
        typename Iterator::value_type key = *i;
        Iterator j = i;

        while (j != begin && *std::prev(j) > key) {
            *j = *std::prev(j);
            --j;
        }
        *j = key;
    }
}

template <typename Container>
void mergeInsertionSort(Container& container, typename Container::iterator begin, typename Container::iterator end) {
    if (std::distance(begin, end) <= 12) {
        insertionSort(begin, end);
    } else {
        typename Container::iterator mid = begin;
        std::advance(mid, std::distance(begin, end) / 2);
        mergeInsertionSort(container, begin, mid);
        mergeInsertionSort(container, mid, end);

        // Merge the sorted halves
        std::inplace_merge(begin, mid, end);
    }
}


template <typename Container>
void displaySequence(const Container& container) {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
clock_t runSorting(Container& container, char **argv, int argc) {
    clock_t startTime = getCurrentTimeMicros< typename Container::value_type >();
    for (int i = 1; i < argc; i++) {
        try {
            int value = std::stoi(argv[i]);
            if (value < 0) {
                std::cout << "Error: Non-positive integer at position " << i << std::endl;
                return 0;
            }
            container.push_back(value);
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: Invalid argument at position " << i << ": " << e.what() << std::endl;
            return 0;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: Out of range at position " << i << ": " << e.what() << std::endl;
            return 0;
        }
    }
    mergeInsertionSort(container, container.begin(), container.end());
    return getCurrentTimeMicros< typename Container::value_type >() - startTime;
}

template <typename Container>
int printNumbers(Container& container, char **argv, int argc) {
    for (int i = 1; i < argc; i++) {
        try {
            container.push_back(std::stoi(argv[i]));
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: Invalid argument at position " << i << ": " << e.what() << std::endl;
            return -1; 
        } catch (const std::out_of_range& e) {
            std::cout << "Error: Out of range at position " << i << ": " << e.what() << std::endl;
            return -1;
        }
    }
    std::cout << "Before: ";
    displaySequence(container);
    mergeInsertionSort(container, container.begin(), container.end());
    std::cout << "After: ";
    displaySequence(container);
    return container.size();
}




#endif
