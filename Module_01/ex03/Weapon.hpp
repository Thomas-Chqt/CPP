/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:22:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/05 00:05:14 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon(const std::string& type);
	const std::string& getType() const;
	void setType(const std::string& type);
	#ifdef DEBUG
		~Weapon();
	#endif // DEBUG

private:
	std::string type;
};

#endif // WEAPON_HPPr