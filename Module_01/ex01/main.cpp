/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:07:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/09 18:54:17 by tchoquet         ###   ########.fr       */
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
	system("leaks -q more_brainz_debug");
}

#endif // MEMCHECK

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie* horde = zombieHorde(3, "Mike");

	for (int i = 0; i < 3; i++)
		horde[i].announce();

	for (int i = 0; i < 3; i++)
		horde[i].~Zombie();

	operator delete(horde);
	return 0;
}
