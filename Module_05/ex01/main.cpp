/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:35 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/16 14:09:27 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    
    std::cout << GREEN << "== Basic Test ==" << RESET << std::endl;
    Form f1("Tax", 50, 25);
    try {
        const Form f;
        std::cout << f << std::endl;}
    catch (const std::exception &e){
        std::cerr << RED << "Form creation failed: " << e.what() << RESET << std::endl;
    }


    std::cout << GREEN << "\n== Test Out of range Grade ==" << RESET << std::endl;
    try {
        Form f2("test", 0, 25);
    }
    catch (const std::exception &e){
        std::cerr << RED << "Form creation failed: "  << e.what() << RESET << std::endl;
    }


    std::cout << GREEN << "\n== Signing Test ==" << RESET << std::endl;
    try {
        Bureaucrat alice("Alice", 30);
        std::cout << alice << std::endl;
        std::cout << f1 << std::endl;
        alice.signForm(f1);
    }
    catch (const std::exception &e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }


    std::cout << GREEN << "\n== Exception Test ==" << RESET << std::endl;
    try {
        Form f3("SecretServices", 10, 5);
        Bureaucrat bob("Bob", 100);
        std::cout << bob << std::endl;
        std::cout << f3 << std::endl;
        bob.signForm(f3);
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return (0);
}