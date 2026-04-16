/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:06:46 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/16 14:16:05 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _formName("defaultForm"), _signed(false), _signGrade(50), _execGrade(25) {}

Form::Form(const Form & src) : _formName(src._formName), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string name, const int sGrade, const int eGrade) : _formName(name), _signed(false) , _signGrade(sGrade), _execGrade(eGrade){
    if (sGrade < 1 || eGrade < 1)
        throw GradeTooHighException();
    if (sGrade > 150 || eGrade > 150)
        throw GradeTooLowException();
}

Form::~Form(){}

Form & Form::operator=(const Form & src){
    if (this != &src)
        this->_signed = src._signed;
    return (*this);
}

const std::string Form::getFormName() const{
    return (this->_formName);
}

bool Form::getSignStatus() const{
    return (this->_signed);
}

int Form::getSignGrade() const{
    return (this->_signGrade);
}

int Form::getExecGrade() const{
    return (this->_execGrade);
}

void Form::beSigned(const Bureaucrat & b){
    if (b.getGrade() <= this->getSignGrade())
        this->_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, const Form & f){
    std::cout << "Form " << YELLOW << f.getFormName() << RESET << ": signature required grade (" << BLUE << f.getSignGrade() << RESET;
    std::cout << "), execution required grade (" << MAGENTA << f.getExecGrade() << RESET;
    std::cout << "), signature status: " << MAGENTA << f.getSignStatus() << RESET << ".";
    return (o);
}
