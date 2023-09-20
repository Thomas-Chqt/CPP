/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:40 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/20 15:18:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& cp);
	
	void learnMateria(AMateria* materia);
	AMateria* createMateria(const std::string& type);

	~MateriaSource();

private:
	AMateria* materias[4];

public:
	MateriaSource& operator=(const MateriaSource& cp);
};

#endif // MATERIASOURCE_HPP