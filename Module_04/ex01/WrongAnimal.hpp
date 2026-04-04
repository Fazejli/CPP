/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:05:07 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 14:24:11 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const & src);
		~WrongAnimal();

		WrongAnimal & 			operator=(WrongAnimal const & other);
		std::string 			getType() const;
		void					setType(std::string type);
		void			makeSound() const;
	protected:
		std::string _type;
};

#endif