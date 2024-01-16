/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:46:11 by jaurasma          #+#    #+#             */
/*   Updated: 2024/01/10 14:23:01 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
int main(int argc, char **argv) {
    PmergeMe sorter;

    if (argc < 2)  {
        std::cout << "Error" << std::endl;
        return EXIT_FAILURE;
    }
    sorter.sort(argc, argv);
    return EXIT_SUCCESS;
}
