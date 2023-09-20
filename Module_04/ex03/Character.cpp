/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:07:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/20 16:18:59 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("Unknown"), materias()
{
#ifdef DEBUG
	std::cout << "Character default constructor called" << std::endl;
#endif	
}

Character::Character(const std::string& name) : name(name), materias()
{
#ifdef DEBUG
	std::cout << "Character name constructor called" << std::endl;
#endif		
}

Character::Character(const Character& cp) : name(cp.name)
{
#ifdef DEBUG
	std::cout << "Character copy constructor called" << std::endl;
#endif

	cp.materias[0] == nullptr ? materias[0] = nullptr : materias[0] = cp.materias[0]->clone();
	cp.materias[1] == nullptr ? materias[1] = nullptr : materias[1] = cp.materias[1]->clone();
	cp.materias[2] == nullptr ? materias[2] = nullptr : materias[2] = cp.materias[2]->clone();
	cp.materias[3] == nullptr ? materias[3] = nullptr : materias[3] = cp.materias[3]->clone();
}

const std::string& Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (m == nullptr)
		return;

	if (AMateria::isOntheFloor(m))
		return (void)(std::cout << "Materia is on the floor" << std::endl);
		
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] == m)
			return (void)(std::cout << "Materia already equiped" << std::endl);
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] == nullptr)
			return (void)(materias[i] = m);
	}
	
	std::cout << "Inventory full, materia felt on the floor" << std::endl;
	AMateria::addToTheFloor(m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return (void)(std::cout << "Invalid slot id" << std::endl);
		
	if (materias[idx] == nullptr)
		return (void)(std::cout << "No materia in slot " << idx << std::endl);

	AMateria::addToTheFloor(materias[idx]);
	materias[idx] = nullptr;
}

void Character::Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return (void)(std::cout << "Invalid slot id" << std::endl);
		
	if (materias[idx] == nullptr)
		return (void)(std::cout << "No materia in slot " << idx << std::endl);

	materias[idx]->use(target);
}

Character::~Character()
{
#ifdef DEBUG
	std::cout << "Character destructor called" << std::endl;
#endif

	delete materias[0];
	delete materias[1];
	delete materias[2];
	delete materias[3];
}

Character& Character::operator=(const Character& cp)
{
	if (&cp == this)
	{
	#ifdef DEBUG
		std::cout << "Character assignement operator called but nothing done" << std::endl;
	#endif	
	}
	else
	{
	#ifdef DEBUG
		std::cout << "Character assignement operator called" << std::endl;
	#endif

		name = cp.name;
		for (int i = 0; i < 4; i++)
		{
			delete materias[i];
			cp.materias[i] == nullptr ? materias[i] = nullptr : materias[i] = cp.materias[i]->clone();
		}
	}
	return *this;
}
