/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:52:34 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 15:04:27 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(std::string name);
		Cat(Cat const & src);
		~Cat();

		Cat & operator=(Cat const & other);
		void makeSound() const ;
	private:
		std::string _name;
};

#endif