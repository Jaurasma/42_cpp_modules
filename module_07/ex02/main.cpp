/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:39:54 by jaurasma          #+#    #+#             */
/*   Updated: 2023/12/07 14:29:26 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Test with int
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 2;
        }

        std::cout << "Int Array elements: ";
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        Array<double> doubleArray(3);
        for (unsigned int i = 0; i < doubleArray.size(); ++i) {
            doubleArray[i] = i * 1.5;
        }
        // Test with double
        std::cout << "Double Array elements: ";
        for (unsigned int i = 0; i < doubleArray.size(); ++i) {
            std::cout << doubleArray[i] << " ";
        }
        std::cout << std::endl;

        Array<int> copiedIntArray(intArray);
        Array<int> assignedIntArray = intArray;

        std::cout << "Copied Int Array elements: ";
        for (unsigned int i = 0; i < copiedIntArray.size(); ++i) {
            std::cout << copiedIntArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Assigned Int Array elements: ";
        for (unsigned int i = 0; i < assignedIntArray.size(); ++i) {
            std::cout << assignedIntArray[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Attempting to access an out-of-bounds index: ";
        try {
            intArray[intArray.size()] = 42; // Exception should be thrown
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Test with const int
        const Array<int> ConstIntArray(5);

        std::cout << "Const Int Array elements: ";
        for (unsigned int i = 0; i < ConstIntArray.size(); ++i) {
            std::cout << ConstIntArray[i] << " ";
        }
        std::cout << std::endl;

        // Test with const double
        const Array<double> ConstDoubleArray(3);
        
        std::cout << "Const Double Array elements: ";
        for (unsigned int i = 0; i < ConstDoubleArray.size(); ++i) {
            std::cout << ConstDoubleArray[i] << " ";
        }
        std::cout << std::endl;

        // Test construction by copy and assignment operator with const instances
        const Array<int> copiedIntArray(ConstIntArray);
        const Array<int> assignedIntArray = ConstIntArray;

        std::cout << "Copied Const Int Array elements: ";
        for (unsigned int i = 0; i < copiedIntArray.size(); ++i) {
            std::cout << copiedIntArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Assigned Const Int Array elements: ";
        for (unsigned int i = 0; i < assignedIntArray.size(); ++i) {
            std::cout << assignedIntArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Attempting to access an out-of-bounds index: ";
        try {
            ConstIntArray[ConstIntArray.size()]; // This should throw an exception
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     // for (int i = 0; i < MAX_VAL; i++)
//     // {
//     //     std::cout << numbers[i] << " ";
//     // }
//     std::cout << std::endl;
//     delete [] mirror;//
//     return 0;
// }