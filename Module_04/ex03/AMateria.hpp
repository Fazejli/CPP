/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:46:28 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 15:11:52 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>
#include <iostream>

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria & src);
		virtual ~AMateria();
		
		const AMateria & operator=(const AMateria& rhs);
		
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;

		virtual void use(ICharacter& target);
};

#endif