/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:57:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/20 14:34:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class AMateria
{
public:
	AMateria();
	AMateria(const AMateria& cp);
	AMateria(const std::string& type);

	const std::string& getType() const;
	virtual void use(ICharacter& target);
	static void addToTheFloor(AMateria* materia);
	static bool isOntheFloor(AMateria* materia);
	static void deleteFloor();
	
	virtual AMateria* clone() const = 0;
	
	virtual ~AMateria();
	
protected:
	std::string type;

private:
	static AMateria** floor;
	static size_t floor_size;

public:
	AMateria& operator=(const AMateria& cp);
};

#endif // AMATERIA_HPP