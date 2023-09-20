/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:39:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 16:22:41 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

#include "Brain.hpp"

class Animal
{
public:
	Animal();
	Animal(const Animal& cp);
	
	virtual void makeSound() const = 0;
	const std::string& getType() const;
	virtual void new_idea(std::string content);
	void print_ideas();
	
	virtual ~Animal();

protected:
	Animal(const std::string& type, Brain* brain);

	std::string type;
	Brain* brain;

public:
	Animal& operator=(const Animal& cp);
};

#endif // ANIMAL_HPP