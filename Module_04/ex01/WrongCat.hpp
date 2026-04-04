/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:08:05 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 14:16:58 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(WrongCat const & src);
		~WrongCat();

		WrongCat & operator=(WrongCat const & other);
		void			makeSound() const;
	private:
		std::string _name;
};

#endif