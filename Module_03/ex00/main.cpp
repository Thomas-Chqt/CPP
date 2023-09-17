/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:00:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/16 16:41:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

int main()
{
	{
		ClapTrap kim;
		ClapTrap jimmy("Jimmy");
		ClapTrap chuck(jimmy);
		kim = jimmy;
	}
	std::cout << std::endl;
	{
		ClapTrap jimmy("Jimmy");
		
		for (int i = 0; i < 10; i++)
			jimmy.attack("Chuck");
		jimmy.attack("Chuck");
		jimmy.beRepaired(5);
	}
	std::cout << std::endl;
	{
		ClapTrap jimmy("Jimmy");
		
		jimmy.takeDamage(10);
		jimmy.attack("Chuck");
	}
	std::cout << std::endl;
	{
		ClapTrap jimmy("Jimmy");
		
		jimmy.takeDamage(5);
		jimmy.beRepaired(5);
		jimmy.takeDamage(5);
		jimmy.takeDamage(5);
		jimmy.takeDamage(5);
	}

	return 0;
}
