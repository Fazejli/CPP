/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:07:56 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/04 00:21:21 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

class Cure : public AMateria {
	private:
		std::string _type;
	public:
		Cure();
		Cure(const Cure & src);
		virtual ~Cure();
		
		const Cure & operator=(const Cure &rhs);
		Cure * clone() const;
		void use(ICharacter& target);
};

#endif