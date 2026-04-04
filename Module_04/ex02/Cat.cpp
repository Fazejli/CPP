/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:51:29 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 17:12:19 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"

Cat::Cat() : AAnimal(), _name("Unknown"){
	this->_brain = new Brain();
	std::cout << "Cat default constructor called." << std::endl;
	this->setType("Cat");
}

Cat::Cat(std::string name) : AAnimal(), _name(name){
	this->_brain = new Brain();
	std::cout << "Cat constructor called." << std::endl;
	this->setType("Cat");
}

Cat::Cat(Cat const & src) : AAnimal(src), _name(src._name){
	this->_brain = new Brain(*src._brain);
	std::cout << "Cat copy constructor called." << std::endl;
	this->setType("Cat");
}

Cat & Cat::operator=(Cat const &other){
	//std::cout << "Assignment operator called." << std::endl;
	if (this != &other){
		this->_type = other.getType();
		this->_name = other._name;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Miaaaouu 🐱 .." << std::endl;
}

Cat::~Cat(){
	delete this->_brain;
	std::cout << "Cat " << this->_name << " is destroyed" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->_brain;
}