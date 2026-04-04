/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:41:17 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 14:25:05 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	public:
		Dog();
		Dog(std::string name);
		Dog(Dog const & src);
		~Dog();

		Dog & operator=(Dog const & other);
		void	makeSound() const;
		Brain* getBrain() const;
	private:
		std::string _name;
		Brain* _brain;
};

#endif