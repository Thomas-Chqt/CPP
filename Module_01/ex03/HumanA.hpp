/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:44:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/05 00:08:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(const std::string& name, Weapon& weapon);
	void attack() const;
	void setWeapon(Weapon& weapon);
	#ifdef DEBUG
		~HumanA();
	#endif // DEBUG

protected:
	HumanA(const std::string& name, Weapon* weapon);

private:
	std::string name;
	Weapon* weapon;
};

#endif // HUMAN_A_HPP
