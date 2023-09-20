/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:11:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/20 16:07:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : materias()
{
#ifdef DEBUG
	std::cout << "MateriaSource default constructor called" << std::endl;
#endif		
}

MateriaSource::MateriaSource(const MateriaSource& cp)
{
#ifdef DEBUG
	std::cout << "MateriaSource copy constructor called" << std::endl;
#endif

	cp.materias[0] == nullptr ? materias[0] = nullptr : materias[0] = cp.materias[0]->clone();
	cp.materias[1] == nullptr ? materias[1] = nullptr : materias[1] = cp.materias[1]->clone();
	cp.materias[2] == nullptr ? materias[2] = nullptr : materias[2] = cp.materias[2]->clone();
	cp.materias[3] == nullptr ? materias[3] = nullptr : materias[3] = cp.materias[3]->clone();
}

void MateriaSource::learnMateria(AMateria* materia)
{		
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] == nullptr)
			return (void)(materias[i] = materia);
	}
	
	std::cout << "Materia source full, materia felt on the floor" << std::endl;
	AMateria::addToTheFloor(materia);
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return nullptr;
}

MateriaSource::~MateriaSource()
{
#ifdef DEBUG
	std::cout << "MateriaSource destructor called" << std::endl;
#endif

	delete materias[0];
	delete materias[1];
	delete materias[2];
	delete materias[3];	
}

MateriaSource& MateriaSource::operator=(const MateriaSource& cp)
{
	if (&cp == this)
	{
	#ifdef DEBUG
		std::cout << "MateriaSource assignement operator called but nothing done" << std::endl;
	#endif	
	}
	else
	{
	#ifdef DEBUG
		std::cout << "MateriaSource assignement operator called" << std::endl;
	#endif

		for (int i = 0; i < 4; i++)
		{
			delete materias[i];
			cp.materias[i] == nullptr ? materias[i] = nullptr : materias[i] = cp.materias[i]->clone();
		}
	}
	return *this;	
}
