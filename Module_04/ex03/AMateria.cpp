/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:02:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/20 14:43:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria** AMateria::floor = nullptr;
size_t AMateria::floor_size = 0;

AMateria::AMateria() : type("No type")
{
#ifdef DEBUG
	std::cout << "AMateria default constructor called" << std::endl;
#endif
}

AMateria::AMateria(const AMateria& cp) : type("No type")
{
#ifdef DEBUG
	std::cout << "AMateria copy constructor called" << std::endl;
#endif

	(void)cp;
}

AMateria::AMateria(const std::string& type) : type(type)
{
#ifdef DEBUG
	std::cout << "AMateria type constructor called" << std::endl;
#endif
}

const std::string& AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used on " << target.getName() << std::endl;
}

void AMateria::addToTheFloor(AMateria* materia)
{
	AMateria** new_floor = new AMateria*[floor_size + 1];
	
	for (uint64_t i = 0; i < floor_size; i++)
		new_floor[i] = floor[i];
	new_floor[floor_size] = materia;
	
	delete[] floor;
	floor = new_floor;
	floor_size++;
}

bool AMateria::isOntheFloor(AMateria* materia)
{
	for (uint64_t i = 0; i < floor_size; i++)
	{
		if (floor[i] == materia)
			return true;
	}
	return false;
}

void AMateria::deleteFloor()
{
	for (uint64_t i = 0; i < floor_size; i++)
	{
		delete floor[i];
	}
	delete[] floor;
}

AMateria::~AMateria()
{
#ifdef DEBUG
	std::cout << "AMateria destructor called" << std::endl;
#endif		
}

AMateria& AMateria::operator=(const AMateria& cp)
{
	if (&cp == this)
	{
	#ifdef DEBUG
		std::cout << "AMateria assignement operator called but nothing done" << std::endl;
	#endif	
	}
	else
	{
	#ifdef DEBUG
		std::cout << "AMateria assignement operator called" << std::endl;
	#endif	
	}
	return *this;
}