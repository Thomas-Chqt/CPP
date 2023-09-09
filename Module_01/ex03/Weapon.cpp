/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:34:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/05 00:05:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) 
{
	#ifdef DEBUG
		std::cout << type << " constructed" << std::endl;
	#endif // DEBUG
}

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}

#ifdef DEBUG
	Weapon::~Weapon()
	{
		std::cout << type << " deleted" << std::endl;
	}
#endif // DEBUG