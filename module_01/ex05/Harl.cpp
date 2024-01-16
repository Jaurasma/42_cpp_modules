/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:05:40 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/27 11:50:03 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "Object Harl created" << std::endl;
}

Harl::~Harl()
{
    std::cout << "Object Harl destroyed" << std::endl;
}

void   Harl::debug(void)
{
    std::cout << "Zaphod: Hey, Ford, did you notice a minor glitch in the code? It seems the answer to the Ultimate Question of Life, the Universe, and Everything is coming out as 42.001. Can you please check it out?" << std::endl << std::endl;
}

void   Harl::info(void)
{
    std::cout << "Arthur: I can't believe it! The Infinite Improbability Drive in our code is malfunctioning, causing strange and unexpected results. This could lead us into all sorts of trouble! We need to resolve it before we end up in an alternate universe." << std::endl << std::endl;
}

void  Harl::warning(void)
{
    std::cout << "Marvin: I knew it! The code is as useful as a personality prototype for a Vogon! These bugs are causing the Heart of Gold's systems to go haywire. If it isn't fixed soon, I'll express my severe dissatisfaction with the entire process in a very melancholic tone." << std::endl << std::endl;
}

void  Harl::error(void)
{
    std::cout << "Slartibartfast: This is absolutely disastrous! The whole planet is about to be blown up, and the code is to blame! If you don't fix it in the next 42 seconds, I'll have to contact the mice and demand they replace you with a supercomputer to run their experiment!" << std::endl << std::endl;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*complaint_pointer[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string harl_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for(int i = 0; i < 4; i++)
    {
        if(level == harl_level[i])
        {
            (this->*complaint_pointer[i])();
            break ;
        }
    }
}
