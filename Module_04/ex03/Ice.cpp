/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:20:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/20 13:39:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
#ifdef DEBUG
	std::cout << "Ice default constructor called" << std::endl;
#endif		
}

Ice::Ice(const Ice& cp) : AMateria("ice")
{
#ifdef DEBUG
	std::cout << "Ice copy constructor called" << std::endl;
#endif

	(void)cp;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
#ifdef DEBUG
	std::cout << "Ice destructor called" << std::endl;
#endif
}

Ice& Ice::operator=(const Ice& cp)
{
	if (&cp == this)
	{
	#ifdef DEBUG
		std::cout << "Ice assignement operator called but nothing done" << std::endl;
	#endif	
	}
	else
	{
	#ifdef DEBUG
		std::cout << "Ice assignement operator called" << std::endl;
	#endif	
	}
	return *this;
}