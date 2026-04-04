/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:19 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/04 00:03:31 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		ScavTrap();
		virtual ~ScavTrap();

		ScavTrap & 	operator=(ScavTrap const & other);
		void 		guardGate();
		void	attack(const std::string& target);

		void setHitPoints(int hp);
		void setNrjPoints(int energy);
		void setAttackDamage(int damage);
};

std::ostream & operator<<(std::ostream & o, ScavTrap const & i);

#endif