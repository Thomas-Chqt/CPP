/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:26:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/17 15:34:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& cp);

	void highFivesGuys();

	~FragTrap();

protected:
	virtual uint32_t inital_hit_pts() const;
	virtual uint32_t inital_energy_pts() const;
	virtual uint32_t inital_atk_dmg() const;
};

#endif // FRAGTRAP_HPP