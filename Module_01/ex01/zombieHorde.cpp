/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:10:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/09 18:53:50 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* arr = (Zombie*)operator new[](sizeof(Zombie) * N);
	for (int i = 0; i < N; i++)
		new(arr + i) Zombie(name);
	return arr;
}