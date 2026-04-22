/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:45:59 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/21 18:40:26 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename T>
typename T::iterator EasyFind(T &any, int n){
    typename T::iterator it = std::find(any. begin(), any.end(), n);
    if (it == any.end()){
        throw
            std::runtime_error("ERROR: Value not found");}
    return it;
}

#endif