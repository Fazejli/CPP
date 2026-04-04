/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:29:28 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 17:00:21 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("_default"){
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal destructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type){
	std::cout << "Animal constructor called." << std::endl;
	this->setType("_default");
}

Animal::Animal(Animal const & src){
	std::cout << "Animal copy constructor called." << std::endl;
	*this = src;
}

std::string Animal::getType() const {
	return (this->_type);
}

void Animal::setType(std::string type){
	this->_type = type;	
}

void Animal::makeSound() const {
	std::cout << "Default animal sound: Rooooaaar 🦖 .." << std::endl;
}

Animal & Animal::operator=(Animal const & other){
	//std::cout << "Assignment operator called." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return *this;
}