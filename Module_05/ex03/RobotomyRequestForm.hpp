/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:50:18 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/16 15:04:02 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;
    
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(const RobotomyRequestForm & src);

        void execute(Bureaucrat const & executor) const;
};

#endif