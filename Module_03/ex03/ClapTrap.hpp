/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:48 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 12:29:40 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap{

	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const & src);
		ClapTrap(std::string name);
		virtual ~ClapTrap();

		ClapTrap & operator=(ClapTrap const & other);

		std::string getName() const;
		int			getHitPoints() const;
		int			getNrjPoints() const;
		int			getAttackDamage() const;

		void		setHitPoints(int hp) ;
		void		setNrjPoints(int energy) ;
		void		setAttackDamage(int damage) ;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

};

std::ostream & operator<<(std::ostream & o, ClapTrap const & i);

#endif
