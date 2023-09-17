/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:40:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/17 16:33:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap()
	:	ClapTrap("", inital_hit_pts(), inital_energy_pts(), inital_atk_dmg()),
		name("")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	:	ClapTrap(name + "_clap_name", inital_hit_pts(), inital_energy_pts(), inital_atk_dmg()),
		name(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& cp) : ClapTrap(cp), name(cp.name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "Name: " << name << " | ClapTrap name: " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

uint32_t DiamondTrap::inital_hit_pts() const
{
	return FragTrap::inital_hit_pts();
}

uint32_t DiamondTrap::inital_energy_pts() const
{
	return ScavTrap::inital_energy_pts();
}

uint32_t DiamondTrap::inital_atk_dmg() const
{
	return FragTrap::inital_atk_dmg();
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& cp)
{
	ClapTrap::operator=(cp);
	name = cp.name;

	std::cout << "DiamondTrap assignment operator called" << std::endl;
	return *this;
}