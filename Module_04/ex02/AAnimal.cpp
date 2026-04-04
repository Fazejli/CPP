/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:29:28 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 17:23:04 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("_default"){
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type){
	std::cout << "AAnimal constructor called." << std::endl;
	this->setType("_default");
}

AAnimal::AAnimal(AAnimal const & src){
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = src;
}

std::string AAnimal::getType() const {
	return (this->_type);
}

void AAnimal::setType(std::string type){
	this->_type = type;	
}

AAnimal & AAnimal::operator=(AAnimal const & other){
	//std::cout << "Assignment operator called." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return *this;
}