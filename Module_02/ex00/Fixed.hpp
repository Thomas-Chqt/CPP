/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:57:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/13 23:09:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& copy);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed& operator=(const Fixed& copy);

	~Fixed();
private:
	static const int fractionBitsCount;
	int rawBits;
};

#endif // FIXED_HPP