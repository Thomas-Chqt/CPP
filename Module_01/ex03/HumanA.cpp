/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:25:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/05 00:06:23 by tchoquet         ###   ########.fr       */
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
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
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