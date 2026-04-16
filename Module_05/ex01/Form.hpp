/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:50:34 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/16 13:14:52 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string _formName;
        bool    _signed;
        const int _signGrade;
        const int _execGrade;
    public:
        Form();
        Form(const Form & src);
        Form(const std::string name, const int sGrade, const int eGrade);
        virtual ~Form();

        Form & operator=(const Form & src);

        const std::string getFormName() const;
        bool        getSignStatus() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        class GradeTooHighException : public std::exception{
			public:
        		const  char * what() const throw() {
            		return("Invalid grade: Too High (out of range : 1 - 150)");}};
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw(){
					return("Invalid grade: Too Low (out of range : 1 - 150)");}};
        void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &o, const Form & f);


#endif