/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:35 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/16 13:48:10 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){

	try {
		std::cout << GREEN << "== Basic Test == " << RESET << std::endl;
		const Bureaucrat a;
		Bureaucrat b("player", 1);
		Bureaucrat test("test", 10);
		test = b; 
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << test << std::endl;

		std::cout << std::endl;
		std::cout << GREEN << "== More Tests == " << RESET << std::endl;

		Bureaucrat c("Bob", 2);
		std::cout << c << std::endl;
		std::cout << c++ << std::endl;
		std::cout << c << std::endl;
		//std::cout << c++ << std::endl;
		std::cout << std::endl;
		Bureaucrat d("Lambda", 12);
		d = a;
		std::cout << d << std::endl;
		std::cout << d-- << std::endl;
		std::cout << d << std::endl;
	}
	catch (const std::exception & e){
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}