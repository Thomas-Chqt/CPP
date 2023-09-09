/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:47:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/09 16:47:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Harl.hpp"

Harl::Harl()
{
	func_ptrs[0] = &Harl::debug;
	func_ptrs[1] = &Harl::info;
	func_ptrs[2] = &Harl::warning;
	func_ptrs[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	int index = get_index(level);
	if (index >= 0)
		(this->*func_ptrs[index])();
}

int Harl::get_index(std::string& level)
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
