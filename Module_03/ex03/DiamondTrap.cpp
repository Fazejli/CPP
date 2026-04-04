/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:50 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 12:23:35 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_d_clap_name"), FragTrap(), ScavTrap(){
	std::cout << "DiamondTrap default constructor is called and ";
	this->_name = "default_d";
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getNrjPoints();
	this->_attackDamage = 30;
	std::cout << this->_name << " is created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name){
	std::cout << "DiamondTrap assignation constructor is called and ";
	this->_name = name;
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getNrjPoints();
	this->_attackDamage = 30;
	std::cout << this->_name << " is created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), FragTrap(src), ScavTrap(src){
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap default destructor called and " << this->_name;
	std::cout << " is destroyed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & othr){
	//std::cout << "Operator assignation called" << std::endl;
	if (this != &othr)
	{
		this->_name = othr._name;
		this->_hitPoints = othr._hitPoints;
		this->_energyPoints = othr._energyPoints;
		this->_attackDamage = othr._attackDamage;
	}
	return (*this);
}

void DiamondTrap::whoAmI(){
	std::cout << "My name is " << this->_name << " and My ClapTrap's name is ";
	std::cout << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(std::string target){
	ScavTrap::attack(target);
}
