/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:32:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/03 19:48:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Zombie.hpp"

#ifdef MEMCHECK

__attribute__((destructor))
static void destructor(void)
{
	std::cout << std::endl;
	system("leaks -q brainz_debug");
}

#endif // MEMCHECK

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	std::cout << "Using newZombie() :" << std::endl;
	Zombie* zmb = newZombie("John");
	zmb->announce();
	delete zmb;

	std::cout << std::endl;

	std::cout << "Using randomChump() :" << std::endl;
	randomChump("Brian");

	return 0;
}
