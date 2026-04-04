/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:22:04 by fadzejli          #+#    #+#             */
/*   Updated: 2026/02/18 18:06:47 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Zombie{
    private:
    const std::string _name;

    public:
    Zombie(const std::string name);
    ~Zombie();
    void announce(void);
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif