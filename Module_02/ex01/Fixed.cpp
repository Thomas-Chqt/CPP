/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:57:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/13 23:29:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

const int Fixed::fractionBitsCount = 8;

Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = copy;
}

Fixed::Fixed(const int nbr) : rawBits(int32_t(nbr << fractionBitsCount))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr)
	: rawBits(int32_t(nbr * float(1 << fractionBitsCount) + (nbr >= 0 ? 0.5 : -0.5)))
{
	std::cout << "Float constructor called" << std::endl;	
}

float Fixed::toFloat(void) const
{
	return float(rawBits) / float(1 << fractionBitsCount);
}

int Fixed::toInt(void) const
{
	return int(rawBits >> fractionBitsCount);
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	if (this != &copy)
	{
		std::cout << "Copy assignment operator called" << std::endl;

		rawBits = copy.rawBits;
	}
	else
		std::cout << "Copy assignment operator called but nothing done" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& val)
{
	stream << val.toFloat();
	return stream;
}
