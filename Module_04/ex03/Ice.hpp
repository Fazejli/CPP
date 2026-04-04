/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:19:43 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/04 00:20:12 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice & src);
		virtual ~Ice();
		
		const Ice & operator=(const Ice &rhs);
		Ice * clone() const;
		void use(ICharacter& target);
};

#endif