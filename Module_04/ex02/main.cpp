/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:53:13 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 14:41:20 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //Error test
    //AAnimal a;
    
    // Basic test
    AAnimal* dog = new Dog("Billy");
    AAnimal* cat = new Cat();
    
    dog->makeSound();
    cat->makeSound();
    
    delete dog;
    delete cat;
    
    return 0;
}