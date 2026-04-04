/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:53:13 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 13:16:30 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "===== Basic Test =====" << std::endl;
	const Animal* meta = new Animal();
    std::cout << "Meta's type is: " << meta->getType() << ", and his sound is: ";
    meta->makeSound();
	std::cout << std::endl;
	const Animal* Bobby = new Dog();
	std::cout << "Bobby's type is: " << Bobby->getType() << ", and his sound is: ";
    Bobby->makeSound();
	std::cout << std::endl;
	Animal* Garfield = new Cat();
	std::cout << "Meta's type is: " << Garfield->getType() << ", and his sound is: ";
    Garfield->makeSound();
	std::cout << std::endl;
    delete meta;
    delete Bobby;
	delete Garfield;
	
	std::cout << "\n===== More Tests =====" << std::endl;
	WrongCat i("Jerry");
	std::cout << "Jerry's type is: " << i.getType() << ", and his sound is: ";
	i.makeSound();
	std::cout << std::endl;
	WrongAnimal *j = new WrongCat("Simba");
	std::cout << "Simba's type is: " << j->getType() << ", and his sound is: ";
	j->makeSound();
	
    delete j;
	return 0;
}

/*int main()
{
	const WrongAnimal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
	return (0);
}*/