/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:26:52 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/17 15:41:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& cp);
	
	void attack(const std::string& target);
	void whoAmI();

	~DiamondTrap();
	
protected:
	uint32_t inital_hit_pts() const;
	uint32_t inital_energy_pts() const;
	uint32_t inital_atk_dmg() const;
	
private:
	std::string name;

public:
	DiamondTrap& operator=(const DiamondTrap& cp);
};

#endif // DIAMONDTRAP_HPP