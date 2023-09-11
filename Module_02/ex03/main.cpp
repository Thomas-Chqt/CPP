/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:57:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/11 14:52:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point A(1, 2);
	Point B(6, 9);
	Point C(10, 4);

	Point point(2, 3);

	if (bsp(A, B, C, point))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not inside" << std::endl;
	return 0;
}
