/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:59:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/11 14:23:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& cp);

	const Fixed& X() const;
	const Fixed& Y() const;

	Point& operator=(const Point& cp);
	
	~Point();
private:
	const Fixed x;
	const Fixed y;
};

#endif // POINT_HPP