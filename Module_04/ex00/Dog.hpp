/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:41:17 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 12:36:25 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(std::string name);
		Dog(Dog const & src);
		~Dog();

		Dog & operator=(Dog const & other);
		void	makeSound() const;
	private:
		std::string _name;
};

#endif