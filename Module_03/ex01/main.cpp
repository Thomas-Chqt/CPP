/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:00:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/17 14:48:18 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// {
	// 	ClapTrap kim;
	// 	ClapTrap jimmy("Jimmy");
	// 	ClapTrap chuck(jimmy);
	// 	kim = jimmy;
	// }
	// std::cout << std::endl;
	// {
	// 	ClapTrap jimmy("Jimmy");
		
	// 	for (int i = 0; i < 10; i++)
	// 		jimmy.attack("Chuck");
	// 	jimmy.attack("Chuck");
	// 	jimmy.beRepaired(5);
	// }
	// std::cout << std::endl;
	// {
	// 	ClapTrap jimmy("Jimmy");
		
	// 	jimmy.takeDamage(10);
	// 	jimmy.attack("Chuck");
	// }
	// std::cout << std::endl;
	// {
	// 	ClapTrap jimmy("Jimmy");
		
	// 	jimmy.takeDamage(5);
	// 	jimmy.beRepaired(5);
	// 	jimmy.takeDamage(5);
	// 	jimmy.takeDamage(5);
	// 	jimmy.takeDamage(5);
	// }
	// std::cout << std::endl;
	
	{
		ScavTrap lalo;
		ScavTrap gus("Gus");
		ScavTrap hector(gus);
		lalo = gus;
	}
	std::cout << std::endl;
	{
		ClapTrap jimmy(ScavTrap("Jimmy"));
		jimmy.beRepaired(1);
	}
	std::cout << std::endl;
	{
		ScavTrap mike = std::string("Mike");
		mike.attack("Tuco");
		mike.takeDamage(20);
		mike.attack("Tuco");
		mike.beRepaired(1000);
		mike.guardGate();
	}

	return 0;
}
