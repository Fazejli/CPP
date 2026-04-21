/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:45:59 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/21 13:41:22 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <iostream>

#include <algorithm>

template <typename T>
typename T::iterator EasyFind(T& any, int nb){
    typename T::iterator it = std::find(any.begin(), any.end(), nb);
    if (it != any.end())
        return (it);
    else
        throw std::runtime_error("Value not found");
}

#endif