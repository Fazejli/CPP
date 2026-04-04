/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:42:58 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 12:39:44 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal(), _name("Unknown"){
	std::cout << "Dog default constructor called." << std::endl;
	this->setType("Dog");
}

Dog::Dog(std::string name) : Animal("Dog"), _name(name){
	std::cout << "Dog assignation constructor called." << std::endl;
	this->setType("Dog");
}

Dog::Dog(Dog const & src) : Animal("Dog"), _name(src._name){
	std::cout << "Dog copy constructor called." << std::endl;
	this->setType("Dog");
}

Dog & Dog::operator=(Dog const &other){
	//std::cout << "Assignation operator called." << std::endl;
	if (this != &other){
		this->_type = other.getType();
		this->_name = other._name;}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Wof Wof 🐶 .." << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog " << this->_name << " is destroyed." << std::endl;
}