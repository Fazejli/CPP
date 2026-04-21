/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:46:40 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/21 13:41:09 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

#include <vector>
#include <list>

int main()
{
    std::cout << GREEN << "== Basic <vector> test ==" << RESET << std::endl;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(42);
    
    try {
        std::cout << "Searching '2' in vector<int> v.." << std::endl;
        std::vector<int>::iterator it = EasyFind(v, 2);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "== Error <list> test ==" << RESET << std::endl;
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);

    try {
        std::cout << "Searching '42' in list<int> l.." << std::endl;
        std::list<int>::iterator it = EasyFind(l, 42);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    return 0;
}