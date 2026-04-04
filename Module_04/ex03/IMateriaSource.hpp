/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:00:18 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/04 00:35:15 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIASOURCE_HPP
#define AMATERIASOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource
{
    public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif