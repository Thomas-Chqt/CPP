/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:57:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/13 23:27:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int nbr);
	Fixed(const float nbr);

	float toFloat(void) const;
	int toInt(void) const;

	Fixed& operator=(const Fixed& copy);

	~Fixed();
private:
	static const int fractionBitsCount;
	int32_t rawBits;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& val);

#endif // FIXED_HPP