/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:41:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 14:26:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal() : type("Animal"), brain(new Brain)
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& cp) : type("Animal"), brain(new Brain(*cp.brain))
{
	std::cout << "Animal copy constructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Random animal sound" << std::endl;
}

const std::string& Animal::getType() const
{
	return type;
}

void Animal::new_idea(std::string content)
{
	brain->new_idea(content);
}

void Animal::print_ideas()
{
	brain->print_ideas();
}

Animal::~Animal()
{
	delete brain;
	
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const std::string& type, Brain* brain) : type(type), brain(brain)
{
	std::cout << "Animal protected constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& cp)
{
	if (this == &cp)
		std::cout << "Animal assignement operator called but nothing done" << std::endl;
	else
	{
		std::cout << "Animal assignement operator called" << std::endl;

		*brain = *cp.brain;
	}
	return *this;
}