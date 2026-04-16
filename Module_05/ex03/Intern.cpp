/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:58:09 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/16 15:27:33 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern & s){
    *this = s;
}

Intern::~Intern(){}

Intern &Intern::operator=(const Intern & s){
    (void)s;
    return *this;
}

AForm* Intern::createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target) {
    return new PresidentialPardonForm(target);
}
    
AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    FormCreator creators[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };
    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            std::cout << "Intern creates form " << CYAN << formName << RESET << std::endl;
            return creators[i](target);
        }
    }
    std::cout << RED << "Error: form \"" << formName << "\" does not exist." << RESET << std::endl;
    return NULL;
}
