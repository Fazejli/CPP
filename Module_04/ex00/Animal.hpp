/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:29:30 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 12:50:25 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const & src);
		virtual ~Animal();

		Animal & 				operator=(Animal const & other);
		std::string 			getType() const;
		void					setType(std::string type);
		virtual void			makeSound() const;
	protected:
		std::string _type;
};

#endif