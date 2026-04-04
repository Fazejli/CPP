/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:41:17 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 17:12:46 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
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