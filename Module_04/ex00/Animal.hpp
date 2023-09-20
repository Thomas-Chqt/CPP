/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:39:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 11:41:40 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
public:
	Animal();
	Animal(const Animal& cp);
	
	virtual void makeSound() const;
	const std::string& getType() const;

	virtual ~Animal();

protected:
	Animal(const std::string& type);

private:
	std::string type;

public:
	Animal& operator=(const Animal& cp);
};

#endif // ANIMAL_HPP