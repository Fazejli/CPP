/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:52 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 12:15:31 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap& src);
		DiamondTrap(std::string name);
		virtual ~DiamondTrap();
		
		DiamondTrap& operator=(DiamondTrap const & othr);
		void attack(std::string target);
		void whoAmI();
};

#endif