/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:02:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/17 14:38:49 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& cp);
	
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	~ClapTrap();
	
protected:
	ClapTrap(const std::string& name, uint32_t hit_pts, uint32_t energy_pts, uint32_t atk_dmg);

	virtual uint32_t inital_hit_pts() const;
	
	std::string name;
	uint32_t hit_pts;
	uint32_t energy_pts;
	uint32_t atk_dmg;

public:
	ClapTrap& operator=(const ClapTrap& cp);
};

#endif // CLAPTRAP_HPP