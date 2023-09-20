/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:05:27 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/17 19:06:14 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cp) : type("WrongAnimal")
{
	(void)cp;
	
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Random wrong animal sound" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
	std::cout << "WrongAnimal protected constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& cp)
{
	if (this == &cp)
		std::cout << "WrongAnimal assignement operator called but nothing done" << std::endl;
	else
		std::cout << "WrongAnimal assignement operator called" << std::endl;
	return *this;
}