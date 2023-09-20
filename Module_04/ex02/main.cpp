/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:38:20 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 15:28:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#ifdef MEMCHECK

__attribute__((destructor))
static void	destructor(void)
{
	std::cout << std::endl;
	system("leaks -q abstract_debug");
}

#endif // MEMCHECK

/*
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

int main()
{
	std::cout << "\033[0;32m----Brain constructors----\033[0m" << std::endl;
	{
		Brain brain;
		Brain brain2(brain);
		brain = brain2;
	}
	std::cout << std::endl;
	
	std::cout << "\033[0;32m----Brain usage----\033[0m" << std::endl;
	{
		Brain brain;

		std::cout << "\033[0;33m"; brain.print_ideas(); std::cout << "\033[0m";
		
		std::cout << "\033[0;32mAdding 2 ideas to the brain\033[0m" << std::endl;
		brain.new_idea("Idea one");
		brain.new_idea("Idea two");

		std::cout << "\033[0;33m"; brain.print_ideas(); std::cout << "\033[0m";
	}
	std::cout << std::endl;
	
	std::cout << "\033[0;32m----Brain copy----\033[0m" << std::endl;
	{
		Brain brain1;

		std::cout << "\033[0;32mAdding idea to brain 1\033[0m" << std::endl;
		brain1.new_idea("Idea Brain 1");
	
		
		Brain brain2(brain1);
		
		std::cout << "\033[0;32mAdding idea to brain 2\033[0m" << std::endl;
		brain2.new_idea("Idea Brain 2");
		

		Brain brain3;
		brain3 = brain2;

		std::cout << "\033[0;32mAdding idea to brain 3\033[0m" << std::endl;
		brain3.new_idea("Idea Brain 3");
		
		
		std::cout << "\033[0;32mideas brain 1\033[0m" << std::endl;
		std::cout << "\033[0;33m"; brain1.print_ideas(); std::cout << "\033[0m";

		std::cout << "\033[0;32mideas brain 2\033[0m" << std::endl;
		std::cout << "\033[0;33m"; brain2.print_ideas(); std::cout << "\033[0m";
		
		std::cout << "\033[0;32mideas brain 3\033[0m" << std::endl;
		std::cout << "\033[0;33m"; brain3.print_ideas(); std::cout << "\033[0m";
		
	}
	std::cout << std::endl;
	
	std::cout << "\033[0;32m----Animals deep copies----\033[0m" << std::endl;
	{
		Cat cat;
		
		std::cout << "\033[0;32mAdding idea to cat\033[0m" << std::endl;
		cat.new_idea("Cat idea");


		Animal animal(cat);
		
		std::cout << "\033[0;32mAdding idea to animal\033[0m" << std::endl;
		animal.new_idea("Animal idea");
		

		std::cout << "\033[0;32mideas cat\033[0m" << std::endl;
		std::cout << "\033[0;33m"; cat.print_ideas(); std::cout << "\033[0m";
		
		std::cout << "\033[0;32mideas animal\033[0m" << std::endl;
		std::cout << "\033[0;33m"; animal.print_ideas(); std::cout << "\033[0m";
	}
	std::cout << std::endl;
	
	std::cout << "\033[0;32m----Animals array----\033[0m" << std::endl;
	{
		Animal* animals[4] = {
			new Cat,
			new Cat,
			new Dog,
			new Dog,
		};

		delete animals[0];
		delete animals[1];
		delete animals[2];
		delete animals[3];
	}
	
	return 0;
}
*/

int main()
{
	// Animal animal;

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
	
	return 0;
}
