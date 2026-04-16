/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:22:35 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/16 14:38:54 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45) , _target("default_target"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string name) : AForm("RobotomyRequestForm", 72, 45), _target(name) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & f) : AForm(f), _target(f._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & src){
    if (this != &src)
        *this = src;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (executor.getGrade() > this->getExecGrade() || this->getSignStatus() != true){
        throw
            GradeTooLowException();}
    else{
        if (rand() % 2 == 0){
            std::cout << "** drilling noise **" << std::endl;
            std::cout << this->_target << " has been robotomized successfull." << std::endl;}
        else
            std::cout << "Robotomy has failed" << std::endl;
    }
}
