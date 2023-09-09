/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:43:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/09 18:19:34 by tchoquet         ###   ########.fr       */
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
    system("leaks -q HarlFilter_debug");
}

#endif


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong arguments" << std::endl;
		return 1;
	}

	Harl harl(argv[1]);
	harl.print_filter();

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
