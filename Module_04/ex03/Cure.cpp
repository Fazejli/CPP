/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:07:31 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/04 00:38:09 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
}

Cure::Cure(const Cure & src) : AMateria("cure"){
	*this = src;
}

Cure::~Cure(){}

const Cure & Cure::operator=(const Cure & rhs){
	(void)rhs;
	return (*this);
}

Cure * Cure::clone() const{
	 return new Cure(*this);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals ";
	std::cout << target.getName() << "'s wounds *" << std::endl;
}