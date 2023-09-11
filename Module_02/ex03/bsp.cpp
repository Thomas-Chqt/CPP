/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:02:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/11 14:52:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed abs(const Fixed& val)
{
	return val > 0 ? val : Fixed(-1) * val;
}

static Fixed area(const Point& A, const Point& B, const Point& C)
{
	return (   A.X() * (B.Y() - C.Y())
		     + B.X() * (C.Y() - A.Y())
		     + C.X() * (A.Y() - B.Y()) ) / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = abs(area(a, b, c));
	Fixed apb = abs(area(a, point, b));
	Fixed bpc = abs(area(b, point, c));
	Fixed cpa = abs(area(c, point, a));

	return (abc == (apb + bpc + cpa));
}
