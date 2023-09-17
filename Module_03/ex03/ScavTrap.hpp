/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:08:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/17 15:37:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& cp);

	virtual void attack(const std::string& target);
	void guardGate();

	~ScavTrap();

protected:
	virtual uint32_t inital_hit_pts() const;
	virtual uint32_t inital_energy_pts() const;
	virtual uint32_t inital_atk_dmg() const;
};

#endif // SCAVTRAP_HPP