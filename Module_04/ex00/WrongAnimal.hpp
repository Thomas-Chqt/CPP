/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:02:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 11:41:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& cp);
	
	void makeSound() const;
	const std::string& getType() const;

	virtual ~WrongAnimal();

protected:
	WrongAnimal(const std::string& type);

private:
	std::string type;

public:
	WrongAnimal& operator=(const WrongAnimal& cp);
};

#endif // WRONGANIMAL_HPP