/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:45:19 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/20 16:19:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#ifdef MEMCHECK

__attribute__((destructor))
static void	destructor(void)
{
	std::cout << std::endl;
	system("leaks -q interface_debug");
}

#endif // MEMCHECK

int main()
{
	{
		ICharacter *jimmy = new Character("Jimmy");
		ICharacter *kim = new Character("Kim");

		jimmy->equip(new Ice);
		jimmy->equip(new Cure);
		jimmy->equip(new Cure);
		jimmy->equip(new Ice);
		
		jimmy->use(0, *kim);
		jimmy->use(1, *kim);
		jimmy->use(2, *jimmy);

		delete jimmy;
		delete kim;
	}
	std::cout << std::endl;
	{
		Character chuck("Chuck");
		Character jimmy("Jimmy");
		
		jimmy.equip(new Ice);
		jimmy.equip(new Cure);
		jimmy.equip(new Cure);
		jimmy.equip(new Ice);

		Character kim(jimmy);
		chuck = kim;
	}
	std::cout << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());

		ICharacter *jimmy = new Character("Jimmy");
		jimmy->equip(src->createMateria("ice"));
		jimmy->equip(src->createMateria("cure"));
		jimmy->equip(src->createMateria("ice"));
		jimmy->equip(src->createMateria("cure"));
		jimmy->equip(src->createMateria("ice"));

		delete jimmy;
		delete src;
		AMateria::deleteFloor();
	}
	return 0;
}
