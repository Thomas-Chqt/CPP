/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:23:30 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/16 18:57:18 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

#define INITIAL_HIT_PTS 10
#define INITIAL_ENERGY_PTS 10
#define INITIAL_ATK_DMG 0

ClapTrap::ClapTrap()
	:	name(""),
		hit_pts(INITIAL_HIT_PTS),
		energy_pts(INITIAL_ENERGY_PTS),
		atk_dmg(INITIAL_ATK_DMG)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	:	name(name),
		hit_pts(INITIAL_HIT_PTS),
		energy_pts(INITIAL_ENERGY_PTS),
		atk_dmg(INITIAL_ATK_DMG)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cp)
	:	name(cp.name),
		hit_pts(cp.hit_pts),
		energy_pts(cp.energy_pts),
		atk_dmg(cp.atk_dmg)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_pts <= 0)
		return (void)(std::cout << "ClapTrap " << name << " is dead" << std::endl);
	if (energy_pts <= 0)
		return (void)(std::cout << "ClapTrap " << name << " Dont have enough energy point to attack" << std::endl);
		

	std::cout << "ClapTrap " << name << " attacks " << target <<", causing " << atk_dmg << " points of damage!" << std::endl;
	energy_pts--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_pts <= 0)
		return (void)(std::cout << "ClapTrap " << name << " is already dead" << std::endl);


	std::cout << "ClapTrap " << name << " take " << amount << " points of damages!" << std::endl;
	hit_pts >= amount ? hit_pts -= amount : hit_pts = 0;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_pts <= 0)
		return (void)(std::cout << "ClapTrap " << name << " is dead" << std::endl);
	if (energy_pts <= 0)
		return (void)(std::cout << "ClapTrap " << name << " Dont have enough energy point to be repaired" << std::endl);
	

	std::cout << "ClapTrap " << name << " is repaired, gaining " << amount << " energy points" << std::endl;
	hit_pts + amount >= INITIAL_HIT_PTS ? hit_pts = INITIAL_HIT_PTS : hit_pts += amount;
	energy_pts--;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& cp)
{
	this->name = cp.name;
	this->hit_pts = cp.hit_pts;
	this->energy_pts = cp.energy_pts;
	this->atk_dmg = cp.atk_dmg;

	std::cout << "ClapTrap assignment operator called" << std::endl;
	return *this;
}
