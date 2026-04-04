/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:47:48 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 17:11:26 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"

Brain::Brain(){
	int i(0);
	std::cout << "Brain default constructor." << std::endl;
	while (i < 100)
	{
		ideas[i] = "";
		i++;
	}
}

Brain::Brain(Brain const & src){
	std::cout << "Brain copy constructor." << std::endl;
	*this = src;
}

Brain::~Brain(){
	std::cout << "Brain is destroyed." << std::endl;
}

Brain & Brain::operator=(Brain const & other){
	//std::cout << "Assignment called" << std::endl;
	int i(0);
	if (this != &other){
		while (i < 100){
			this->ideas[i] = other.getIdea(i);
			i++;
		}
	}
	return (*this);	
}

std::string Brain::getIdea(int index) const{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return ("");
}

void Brain::setIdea(int index, std::string idea){
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}