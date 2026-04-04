/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:29:30 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/04 00:17:24 by fadwa            ###   ########.fr       */
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