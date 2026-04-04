/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 12:24:57 by fadwa             #+#    #+#             */
/*   Updated: 2026/04/04 12:41:17 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

class Character : public ICharacter {
	public:
		Character();
		Character(std::string const & name);
		Character(Character const & src);
		virtual ~Character();

		Character & operator=(Character const & rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria*   _inventory[4];
};

#endif



