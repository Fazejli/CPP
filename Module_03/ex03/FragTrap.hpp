/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:57 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 10:07:12 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(FragTrap const & src);
		FragTrap(std::string name);
		virtual ~FragTrap();

		FragTrap & operator=(FragTrap const & other);

		void highFivesGuys(void);
};

#endif