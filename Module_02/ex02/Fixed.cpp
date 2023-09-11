/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:57:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/13 23:35:49 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

const int Fixed::fractionBitsCount = 8;

Fixed::Fixed() : rawBits(0)
{
	#ifdef DEBUG
		std::cout << "Default constructor called" << std::endl;
	#endif // DEBUG
}

Fixed::Fixed(const Fixed& copy) : rawBits(copy.rawBits)
{
	#ifdef DEBUG
		std::cout << "Copy constructor called" << std::endl;
	#endif // DEBUG
}

Fixed::Fixed(const int nbr) : rawBits(int32_t(nbr << fractionBitsCount))
{
	#ifdef DEBUG
		std::cout << "Int constructor called" << std::endl;
	#endif // DEBUG
}

Fixed::Fixed(const float nbr)
	: rawBits(int32_t(nbr * float(1 << fractionBitsCount) + (nbr >= 0 ? 0.5 : -0.5)))
{
	#ifdef DEBUG
		std::cout << "Float constructor called" << std::endl;
	#endif // DEBUG	
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
		#ifdef DEBUG
			std::cout << "Copy assignment operator called" << std::endl;
		#endif // DEBUG

		rawBits = copy.rawBits;
	}
	else
	{
		#ifdef DEBUG
			std::cout << "Copy assignment operator called but nothing done" << std::endl;
		#endif // DEBUG
	}

	return *this;
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return rawBits < rhs.rawBits;
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return rawBits == rhs.rawBits;
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return rhs < *this;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return *this > rhs || *this == rhs;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return *this < rhs || *this == rhs;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return !(*this == rhs);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed new_fixed = *this;
	new_fixed.rawBits += rhs.rawBits;
	return (new_fixed);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed new_fixed = *this;
	new_fixed.rawBits -= rhs.rawBits;
	return (new_fixed);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed new_fixed = *this;
	new_fixed.rawBits *= int64_t(rhs.rawBits);
	new_fixed.rawBits >>= fractionBitsCount;
	return (new_fixed);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed new_fixed = *this;
	new_fixed.rawBits <<= fractionBitsCount;
	new_fixed.rawBits /= int64_t(rhs.rawBits);
	return (new_fixed);
}

Fixed& Fixed::operator++()
{
	rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	this->operator++();
	return old;
}

Fixed& Fixed::operator--()
{
	rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	this->operator--();
	return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}

Fixed::~Fixed()
{
	#ifdef DEBUG
		std::cout << "Destructor called" << std::endl;
	#endif // DEBUG
}

std::ostream& operator<<(std::ostream& stream, const Fixed& val)
{
	stream << val.toFloat();
	return stream;
}
