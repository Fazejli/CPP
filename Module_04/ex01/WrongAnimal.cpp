/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:03:43 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/04 00:28:45 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("_default"){
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src){
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = src;
}

std::string WrongAnimal::getType() const {
	return (this->_type);
}

void WrongAnimal::setType(std::string type){
	this->_type = type;	
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound: Rooooaaar 🦖 .." << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & other){
	//std::cout << "Assignation operator called.";
	if (this != &other)
		this->_type = other.getType();
	return *this;
}