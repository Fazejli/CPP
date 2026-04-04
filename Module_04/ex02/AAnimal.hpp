/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:29:30 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/04 00:18:39 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const & src);
		virtual ~AAnimal();

		AAnimal & 				operator=(AAnimal const & other);
		std::string 			getType() const;
		void					setType(std::string type);
		virtual void			makeSound() const = 0;
	protected:
		std::string _type;
};

#endif