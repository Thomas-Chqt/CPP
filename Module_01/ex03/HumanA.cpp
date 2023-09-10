/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:25:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/10 15:03:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
	:	name(name), weapon(&weapon)
{
	#ifdef DEBUG
		std::cout << name << " constructed" << std::endl;
	#endif // DEBUG
}

HumanA::HumanA(const std::string& name, Weapon* weapon)
	:	name(name), weapon(weapon)
{
	#ifdef DEBUG
		std::cout << name << " constructed with NULL weapon" << std::endl;
	#endif // DEBUG
}

void HumanA::attack() const
{
	if (weapon != NULL)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " Has no weapon" << std::endl;
		
}

void HumanA::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

#ifdef DEBUG
	HumanA::~HumanA()
	{
		std::cout << name << " deleted" << std::endl;
	}
#endif // DEBUG