/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:42:58 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 17:12:40 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : AAnimal(), _name("Unknown"){
	this->_brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
	this->setType("Dog");
}

Dog::Dog(std::string name) : AAnimal(), _name(name){
	this->_brain = new Brain();
	std::cout << "Dog constructor called." << std::endl;
	this->setType("Dog");
}

Dog::Dog(Dog const & src) : AAnimal(src), _name(src._name){
	this->_brain = new Brain(*src._brain);
	std::cout << "Dog copy constructor called." << std::endl;
	this->setType("Dog");
}

Dog & Dog::operator=(Dog const &other){
	//std::cout << "Assignment operator called." << std::endl;
	if (this != &other){
		this->_type = other.getType();
		this->_name = other._name;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Wof Wof 🐶 .." << std::endl;
}

Brain* Dog::getBrain() const {
    return this->_brain;
}

Dog::~Dog(){
	delete this->_brain;
	std::cout << "Dog " << this->_name << " is destroyed" << std::endl;
}