/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:46:37 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/20 17:26:23 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>


template <typename T>
class Array {
    public:
        Array(){this->_size = 0, this->_array = new T[0];};
        Array(unsigned int size){this->_size = size, this->_array = new T[size];};
        ~Array(){delete[] this->_array;};

        Array(const Array &othr){
            _size = othr._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = othr._array[i];
        };

        class OutOfBounds : public std::exception{
                    public:
                        const char *what() const throw() { 
                        return ("Invalid Index: Out of Bounds");}
                };

        Array &operator=(const Array &othr){
            if (this != &othr){
                delete[] _array;
                _size = othr._size;
                _array = new T[othr._size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = othr._array[i];
                }
            return *this;
        };

        bool operator!=(const Array &othr)const {
            if (_size != othr._size)
                return true;
            for (unsigned int i = 0; i < _size; i++){
                if (this->_array[i] != othr._array[i])
                    return true;
            }
            return false;
        };

        T &operator[](unsigned int index) {
            if (index >= this->_size)
                throw OutOfBounds();
            return (this->_array[index]);
        };
        
        unsigned int size() const{return (this->_size);};
    private:
        T *_array;
        unsigned int _size;
};


#endif