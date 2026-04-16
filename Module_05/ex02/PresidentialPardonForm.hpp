/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:49:29 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/16 14:18:05 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm{
    private:
        std::string _target;
    
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string name);
        PresidentialPardonForm(const PresidentialPardonForm & src);
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=(const PresidentialPardonForm & src);

        void execute(Bureaucrat const & executor) const;
};
#endif