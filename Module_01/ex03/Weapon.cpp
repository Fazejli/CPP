/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:00:48 by fadzejli          #+#    #+#             */
/*   Updated: 2026/02/23 12:02:56 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
    _type = type;
}

Weapon::~Weapon(){
}

const std::string& Weapon::getType(void) const{
    return _type;
}

void Weapon::setType(std::string newType){
    _type = newType;
}