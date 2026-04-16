/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:06:46 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 14:03:30 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _formName("defaultAForm"), _signed(false), _signGrade(50), _execGrade(25) {}

AForm::AForm(const AForm & src) : _formName(src._formName), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string name, const int sGrade, const int eGrade) : _formName(name), _signed(false) , _signGrade(sGrade), _execGrade(eGrade){
    if (sGrade < 1 || eGrade < 1)
        throw GradeTooHighException();
    if (sGrade > 150 || eGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm(){}

AForm & AForm::operator=(const AForm & src){
    //std::cout << "OPerator called" << std::endl;
    if (this != &src)
        this->_signed = src._signed;
    return (*this);
}

const std::string AForm::getFormName() const{
    return (this->_formName);
}

bool AForm::getSignStatus() const{
    return (this->_signed);
}

int AForm::getSignGrade() const{
    return (this->_signGrade);
}

int AForm::getExecGrade() const{
    return (this->_execGrade);
}

void AForm::beSigned(const Bureaucrat & b){
    if (b.getGrade() <= this->getSignGrade())
        this->_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, const AForm & f){
    std::cout << "AForm " << YELLOW << f.getFormName() << RESET << ": signature required grade (" << BLUE << f.getSignGrade() << RESET;
    std::cout << "), execution required grade (" << MAGENTA << f.getExecGrade() << RESET;
    std::cout << "), signature status: " << MAGENTA << f.getSignStatus() << RESET << ".";
    return (o);
}