/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:53:06 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 12:29:50 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		ScavTrap();
		virtual ~ScavTrap();

		ScavTrap & 	operator=(ScavTrap const & other);
		void 		guardGate();
		void		attack(const std::string& target);
};

std::ostream & operator<<(std::ostream & o, ScavTrap const & i);

#endif