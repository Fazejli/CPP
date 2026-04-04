/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:52:34 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 17:14:07 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
	public:
		Cat();
		Cat(std::string name);
		Cat(Cat const & src);
		~Cat();

		Cat & operator=(Cat const & other);
		void makeSound() const ;
		Brain* getBrain() const;

	private:
		std::string _name;
		Brain* _brain;
};

#endif