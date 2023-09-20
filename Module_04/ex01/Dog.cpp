/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:33:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 14:16:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog", new Brain)
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& cp) : Animal("Dog", new Brain(*cp.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;

	(void)cp;
}

void Dog::makeSound() const
{
	std::cout << "Ouaf Ouaf" << std::endl;
}

void Dog::new_idea(std::string content)
{
	Animal::new_idea(content + " and play");
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}