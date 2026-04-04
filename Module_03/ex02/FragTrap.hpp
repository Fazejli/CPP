/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:28 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/04 00:05:22 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(FragTrap const & src);
		FragTrap(std::string name);
		virtual ~FragTrap();

		FragTrap & operator=(FragTrap const & other);

		void highFivesGuys(void);
};

#endif