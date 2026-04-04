/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 12:24:50 by fadwa             #+#    #+#             */
/*   Updated: 2026/04/04 12:46:13 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character():_name("uknown"){
    int i(0);
    while (i < 4)
    {
        _inventory[i] = NULL;
        i++;
    }
}

Character::~Character(){
    for(int i = 0; i < 4; i++)
        delete _inventory[i];
}

Character::Character(std::string const & name) : _name(name){
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(Character const & src) : _name(src._name){
    for (int i = 0; i < 4; i++) {
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character & Character::operator=(Character const & rhs){
    if (this != &rhs)
    {
        this->_name = rhs._name;
        for(int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            if (rhs._inventory[i])
                _inventory[i] = rhs._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return (*this);
}
 
std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m){
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
		if (!_inventory[i])
        {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx){
    if (idx >= 0 && idx < 4)
	    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
    if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}