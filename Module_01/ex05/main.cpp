/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:43:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/08 21:12:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

#ifdef MEMCHECK

#include <stdlib.h>

__attribute__((destructor))
static void destructor(void)
{
    std::cout << std::endl;
    system("leaks -q harl_debug");
}

#endif


int main()
{
	Harl harl;

	while (std::cin.good())
	{
		std::string level;

		std::cout << "Level: ";
		getline(std::cin, level);
		harl.complain(level);
	}
	std::cout << std::endl;
	return 0;
}
