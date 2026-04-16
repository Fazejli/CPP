/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:37 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/16 13:04:57 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){}
		
Bureaucrat::Bureaucrat(const Bureaucrat & src){
	if (src.getGrade() > 150)
		throw GradeTooLowException();
	else if (src.getGrade() < 1)
		throw GradeTooHighException();
	*this = src;
}
	
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name){
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}
		
Bureaucrat &Bureaucrat::operator=(const Bureaucrat & src){
	if (this != &src)
	{
		if (src.getGrade() > 150)
			throw GradeTooLowException();
		else if (src.getGrade() < 1)
			throw GradeTooHighException();
		_grade = src._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

//++i
Bureaucrat &Bureaucrat::operator++(void){
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
	return (*this);
}

//i++
Bureaucrat Bureaucrat::operator++(int idx){
	(void)idx;
	Bureaucrat tmp(this->_name, this->_grade);
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
	return (tmp);
}

//--i
Bureaucrat &Bureaucrat::operator--(void){
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
	return (*this);
}

//i--
Bureaucrat Bureaucrat::operator--(int idx){
	(void)idx;
	Bureaucrat tmp(this->_name, this->_grade);
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
	return (tmp);
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b){
	o << YELLOW << b.getName() << RESET << ", bureaucrat grade " << MAGENTA << b.getGrade() << RESET << ".";
	return o;
}

Bureaucrat::~Bureaucrat(){}
