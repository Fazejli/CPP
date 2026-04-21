/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:48:51 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/20 13:52:56 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

template <typename T>
void swap(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b){
    return (a < b ? a : b);
}

template <typename T>
T max(T a, T b){
    return (a > b ? a : b);
}

#endif