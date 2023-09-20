/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:38:20 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 13:09:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#ifdef MEMCHECK

__attribute__((destructor))
static void	destructor(void)
{
	std::cout << std::endl;
	system("leaks -q polymorphism_debug");
}

#endif // MEMCHECK

void makeSound(const Animal* animal)
{
	animal->makeSound();
}

int main()
{	
	std::cout << "\033[0;32m----Animal tests----\033[0m" << std::endl;
	{
		Animal animal;

		std::cout << "\033[0;33m" << "Type: " << animal.getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; animal.makeSound(); std::cout << "\033[0m";
		
		Animal animal2(animal);
		
		std::cout << "\033[0;33m" << "Type: " << animal2.getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; animal2.makeSound(); std::cout << "\033[0m";
		
		animal = animal2;
		
		std::cout << "\033[0;33m" << "Type: " << animal.getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; animal.makeSound(); std::cout << "\033[0m";
	}
	std::cout << std::endl;


	std::cout << "\033[0;32m----Cat tests----\033[0m" << std::endl;
	{
		Cat cat;

		std::cout << "\033[0;33m" << "Type: " << cat.getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; cat.makeSound(); std::cout << "\033[0m";
		
		Cat cat2(cat);
		
		std::cout << "\033[0;33m" << "Type: " << cat2.getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; cat2.makeSound(); std::cout << "\033[0m";
		
		cat = cat2;
		
		std::cout << "\033[0;33m" << "Type: " << cat.getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; cat.makeSound(); std::cout << "\033[0m";
	}
	std::cout << std::endl;


	std::cout << "\033[0;32m----Dog tests----\033[0m" << std::endl;
	{
		Dog dog;

		std::cout << "\033[0;33m" << "Type: " << dog.getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; dog.makeSound(); std::cout << "\033[0m";
		
		Dog dog2(dog);
		
		std::cout << "\033[0;33m" << "Type: " << dog2.getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; dog2.makeSound(); std::cout << "\033[0m";
		
		dog = dog2;
		
		std::cout << "\033[0;33m" << "Type: " << dog.getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; dog.makeSound(); std::cout << "\033[0m";
	}
	std::cout << std::endl;
	
	
	std::cout << "\033[0;32m----Animal constructed with cat----\033[0m" << std::endl;
	{
		Cat cat;
		Animal animal(cat);

		std::cout << "\033[0;33m" << "Type: " << animal.getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; animal.makeSound(); std::cout << "\033[0m";
	}
	std::cout << std::endl;
	

	std::cout << "\033[0;32mPolymorphism\033[0m" << std::endl;
	{
		const Animal *animal = new Animal;
		const Animal *cat = new Cat;
		const Animal *dog = new Dog;
		
		std::cout << "\033[0;33m" << "Type: " << animal->getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; animal->makeSound(); std::cout << "\033[0m";

		std::cout << "\033[0;33m" << "Type: " << cat->getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; cat->makeSound(); std::cout << "\033[0m";
		
		std::cout << "\033[0;33m" << "Type: " << dog->getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; dog->makeSound(); std::cout << "\033[0m";

		delete animal;
		delete cat;
		delete dog;
	}
	std::cout << std::endl;
	{
		const Animal *animal = new Animal;
		const Animal *cat = new Cat;
		const Animal *dog = new Dog;

		std::cout << "\033[0;33m" << "Type: " << animal->getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; makeSound(animal); std::cout << "\033[0m";

		std::cout << "\033[0;33m" << "Type: " << cat->getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; makeSound(cat); std::cout << "\033[0m";
		
		std::cout << "\033[0;33m" << "Type: " << dog->getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; makeSound(dog); std::cout << "\033[0m";

		delete animal;
		delete cat;
		delete dog;
	}
	std::cout << std::endl;
	
	
	std::cout << "\033[0;32mWrong Polymorphism\033[0m" << std::endl;
	{
		const WrongAnimal *wrong_animal = new WrongAnimal;
		const WrongAnimal *wrong_cat = new WrongCat;

		std::cout << "\033[0;33m";
		
		std::cout << "\033[0;33m" << "Type: " << wrong_animal->getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; wrong_animal->makeSound(); std::cout << "\033[0m";

		std::cout << "\033[0;33m" << "Type: " << wrong_cat->getType() << "\033[0m" << std::endl;
		std::cout << "\033[0;33m" << "Sound: "; wrong_cat->makeSound(); std::cout << "\033[0m";

		std::cout << "\033[0m";

		delete wrong_animal;
		delete wrong_cat;
	}

	return 0;
}
