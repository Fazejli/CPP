/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:39 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/16 15:02:55 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

#include "AForm.hpp"
#include <string>
#include <cmath>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat & src);
		virtual ~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat & src);

		Bureaucrat &operator++(void);
		Bureaucrat operator++(int idx);

		Bureaucrat &operator--(void);
		Bureaucrat operator--(int idx);
		
		std::string getName(void) const;
		int getGrade(void) const;

		class GradeTooHighException : public std::exception{
			public:
        		const  char * what() const throw() {
            		return("Invalid grade: Too High (out of range : 1 - 150)");}};
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw(){
					return("Invalid grade: Too Low (out of range : 1 - 150)");}};
		void signForm(AForm &f);
		void executeForm(AForm const &form) const;
	private:
		const std::string _name;
		int _grade;
	
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif