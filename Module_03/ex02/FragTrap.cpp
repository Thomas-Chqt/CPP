/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:27:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/17 15:07:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#define INITIAL_HIT_PTS 100
#define INITIAL_ENERGY_PTS 100
#define INITIAL_ATK_DMG 30

FragTrap::FragTrap()
	: ClapTrap("", INITIAL_HIT_PTS, INITIAL_ENERGY_PTS, INITIAL_ATK_DMG)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name, INITIAL_HIT_PTS, INITIAL_ENERGY_PTS, INITIAL_ATK_DMG)
{
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& cp) : ClapTrap(cp)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " want to do a high five" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

uint32_t FragTrap::inital_hit_pts() const
{
	return INITIAL_HIT_PTS;
}