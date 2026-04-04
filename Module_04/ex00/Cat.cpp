/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:51:29 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 12:40:30 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal(), _name("Unknown"){
	std::cout << "Cat default constructor called." << std::endl;
	this->setType("Cat");
}

Cat::Cat(std::string name) : Animal(), _name(name){
	std::cout << "Cat constructor called." << std::endl;
	this->setType("Cat");
}

Cat::Cat(Cat const & src) : Animal(src), _name(src._name){
	std::cout << "Cat copy constructor called." << std::endl;
	this->setType("Cat");
}

Cat & Cat::operator=(Cat const &other){
	//std::cout << "Assignation operator called." << std::endl;
	if (this != &other){
		this->_type = other.getType();
		this->_name = other._name;}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Miaaaouu 🐱 .." << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat " << this->_name << " is destroyed" << std::endl;
}