/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:19:22 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/04 00:37:47 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::Ice(const Ice & src) : AMateria("ice"){
	*this = src;
}

Ice::~Ice(){}

const Ice & Ice::operator=(const Ice & rhs){
	(void)rhs;
	return (*this);
}

Ice * Ice::clone() const{
	 return new Ice(*this);
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName() << " *" << std::endl;
}