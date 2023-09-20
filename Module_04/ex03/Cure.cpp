/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:29:38 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/20 13:39:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
#ifdef DEBUG
	std::cout << "Cure default constructor called" << std::endl;
#endif		
}

Cure::Cure(const Cure& cp) : AMateria("cure")
{
#ifdef DEBUG
	std::cout << "Cure copy constructor called" << std::endl;
#endif

	(void)cp;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure()
{
#ifdef DEBUG
	std::cout << "Cure destructor called" << std::endl;
#endif
}

Cure& Cure::operator=(const Cure& cp)
{
	if (&cp == this)
	{
	#ifdef DEBUG
		std::cout << "Cure assignement operator called but nothing done" << std::endl;
	#endif	
	}
	else
	{
	#ifdef DEBUG
		std::cout << "Cure assignement operator called" << std::endl;
	#endif	
	}
	return *this;
}