/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:41:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 13:40:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& cp) : type("Animal")
{
	std::cout << "Animal copy constructor called" << std::endl;
	
	(void)cp;
}

void Animal::makeSound() const
{
	std::cout << "Random animal sound" << std::endl;
}

const std::string& Animal::getType() const
{
	return type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "Animal protected constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& cp)
{
	if (this == &cp)
		std::cout << "Animal assignement operator called but nothing done" << std::endl;
	else
		std::cout << "Animal assignement operator called" << std::endl;
	return *this;
}