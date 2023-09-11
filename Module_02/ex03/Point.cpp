/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:02:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/11 14:24:10 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	#ifdef DEBUG
		std::cout << "Default constructor called (Point)" << std::endl;
	#endif // DEBUG
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	#ifdef DEBUG
		std::cout << "Float constructor called (Point)" << std::endl;
	#endif // DEBUG
}

Point::Point(const Point& cp) : x(cp.x), y(cp.y)
{
	#ifdef DEBUG
		std::cout << "Copy constructor called (Point)" << std::endl;
	#endif // DEBUG
}

const Fixed& Point::X() const
{
	return x;
}

const Fixed& Point::Y() const
{
	return y;
}

Point& Point::operator=(const Point& cp)
{
	if (this != &cp)
	{
		#ifdef DEBUG
			std::cout << "Copy assignment operator called (Point)" << std::endl;
		#endif // DEBUG

		(Fixed)x = cp.x;
		(Fixed)y = cp.y;
	}
	else
	{
		#ifdef DEBUG
			std::cout << "Copy assignment operator called but nothing done (Point)" << std::endl;
		#endif // DEBUG
	}
	return *this;
}

Point::~Point()
{
	#ifdef DEBUG
		std::cout << "Destructor called (Point)" << std::endl;
	#endif // DEBUG
}
