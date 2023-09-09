/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:47:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/09 18:21:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Harl.hpp"

Harl::Harl(const std::string& filter) : filter_index(get_index(filter))
{
	func_ptrs[0] = &Harl::debug;
	func_ptrs[1] = &Harl::info;
	func_ptrs[2] = &Harl::warning;
	func_ptrs[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	int index = get_index(level);
	if (index >= filter_index)
		(this->*func_ptrs[index])();
}

void Harl::print_filter()
{
	switch (filter_index)
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		(this->*func_ptrs[0])();
		std::cout << std::endl;
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		(this->*func_ptrs[1])();
		std::cout << std::endl;
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		(this->*func_ptrs[2])();
		std::cout << std::endl;
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		(this->*func_ptrs[3])();
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int Harl::get_index(const std::string& level)
{
	static std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return i;
	}
	return -1;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
