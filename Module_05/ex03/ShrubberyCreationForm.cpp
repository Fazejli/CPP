/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:15:34 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/17 10:03:54 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137) , _target("default_target"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm("ShrubberyCreationForm", 145, 137), _target(name) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & f) : AForm(f), _target(f._target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & src){
    if (this != &src){
        AForm::operator=(src);
        this->_target = src._target;}
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const{
    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getExecGrade()){
        throw
            GradeTooLowException();}
    else if (this->getSignStatus() == false){
        throw
            UnsignedFormException();}
    std::ofstream f((this->_target + "_shrubbery").c_str());
    f << "    *\n   ***\n  *****\n *******\n    |\n" << std::endl;
    std::cout << CYAN << (this->_target + "_shrubbery").c_str() << " file has been created." << RESET << std::endl;
}
