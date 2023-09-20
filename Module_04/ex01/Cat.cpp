/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:47:04 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 14:14:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat", new Brain)
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& cp) : Animal("Cat", new Brain(*cp.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}

void Cat::new_idea(std::string content)
{
	Animal::new_idea(content + " and sleep");
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}