/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:24:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/02 12:30:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

#ifdef MEMCHECK

__attribute__((destructor))
static void	destructor(void)
{
	std::cout << std::endl;
	system("leaks -q phoneBook_debug");
}

#endif

int main()
{
	PhoneBook phone_book;

	ex01::String cmd;

	while (std::cin.good() && cmd.compare("EXIT") != 0)
	{	
		std::cout << "phoneBook > ";
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0)
			phone_book.add_contact();
		else if (cmd.compare("SEARCH") == 0)
			phone_book.search();
	}
	if (!std::cin.good())
		std::cout << std::endl;
	std::cout << "exit" << std::endl;
	return 0;
}
