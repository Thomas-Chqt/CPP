/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:18:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/17 15:39:14 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define INITIAL_HIT_PTS 100
#define INITIAL_ENERGY_PTS 50
#define INITIAL_ATK_DMG 20

ScavTrap::ScavTrap()
	: ClapTrap("", INITIAL_HIT_PTS, INITIAL_ENERGY_PTS, INITIAL_ATK_DMG)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name, INITIAL_HIT_PTS, INITIAL_ENERGY_PTS, INITIAL_ATK_DMG)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cp) : ClapTrap(cp)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_pts <= 0)
		return (void)(std::cout << "ScavTrap " << name << " is dead" << std::endl);
	if (energy_pts <= 0)
		return (void)(std::cout << "ScavTrap " << name << " Dont have enough energy point to attack" << std::endl);
		

	std::cout << "ScavTrap " << name << " attacks " << target <<", causing " << atk_dmg << " points of damage!" << std::endl;
	energy_pts--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

uint32_t ScavTrap::inital_hit_pts() const
{
	return INITIAL_HIT_PTS;
}

uint32_t ScavTrap::inital_energy_pts() const
{
	return INITIAL_ENERGY_PTS;
}

uint32_t ScavTrap::inital_atk_dmg() const
{
	return INITIAL_ATK_DMG;
}
