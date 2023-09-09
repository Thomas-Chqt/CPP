/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:46:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/05 00:08:12 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : HumanA(name, NULL)
{
	#ifdef DEBUG
		std::cout << name << " constructed" << std::endl;
	#endif // DEBUG
}
