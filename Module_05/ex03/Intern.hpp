/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:53:49 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/10 15:41:12 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <iostream>

class Intern {
    public:
        Intern();
        Intern(const Intern & s);
        ~Intern();

        Intern &operator=(const Intern & s);
        
        AForm *makeForm(std::string name, std::string target);
    
    private:
        typedef AForm* (*FormCreator)(std::string target);
        static AForm* createShrubbery(std::string target);
        static AForm* createRobotomy(std::string target);
        static AForm* createPresidential(std::string target);
};

#endif