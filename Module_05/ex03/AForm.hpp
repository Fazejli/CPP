/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:50:34 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 14:02:44 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string _formName;
        bool    _signed;
        const int _signGrade;
        const int _execGrade;
    public:
        AForm();
        AForm(const AForm & src);
        AForm(const std::string name, const int sGrade, const int eGrade);
        virtual ~AForm();

        AForm & operator=(const AForm & src);

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
        
        class UnsignedFormException: public std::exception {
            public:
                const char * what() const throw(){
                    return("Invalid execution: Form not signed.");
                }};

        void beSigned(const Bureaucrat & b);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, const AForm & f);

#endif