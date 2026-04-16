#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main(void)
{
    std::srand(std::time(NULL));

    Intern someIntern;
    Bureaucrat b;
    AForm *form = NULL;

    try {
        form = someIntern.makeForm("players", "cr7");
        std::cout << *form << std::endl;
    }
    catch (std::exception &e) {
            std::cerr << e.what() << std::endl; }
    delete form;
    form = NULL;
    std::cout << GREEN << "== Basic ShrubberyCreationForm Test ==" << RESET << std::endl;
    try{
        form = someIntern.makeForm("shrubbery creation", "garden");
        std::cout << *form << std::endl;
        try {
            Bureaucrat bob("Bob", 130);
            bob.signForm(*form);
            bob.executeForm(*form);
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl; }
        delete form;
        form = NULL;}
    catch (Intern::UnknownForm & e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n== Basic RobotomyRequestForm Test " << RESET << std::endl;
    form = someIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        std::cout << *form << std::endl;
        try {
            Bureaucrat alice("Alice", 40);
            alice.signForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);
        }
        catch (std::exception &e){ 
            std::cerr << e.what() << std::endl; }
        delete form;
        form = NULL;
    }

    std::cout << GREEN << "\n== Basic PresidentialPardonForm Test " << RESET << std::endl;
    form = someIntern.makeForm("presidential pardon", "Zaphod");
    if (form)
    {
        std::cout << *form << std::endl;
        try {
            Bureaucrat president("President", 1);
            president.signForm(*form);
            president.executeForm(*form);
        }
        catch (std::exception &e){ 
            std::cerr << "Exception: " << e.what() << std::endl; }
        delete form;
        form = NULL;
    }

    std::cout << GREEN << "\n== Test: Non existing Form" << RESET << std::endl;
    try {
            form = someIntern.makeForm("coffee request", "Nobody");
            b.signForm(*form);
            std::cout << "Form created successfully!" << std::endl;}
    catch(std::exception &e){
            std::cerr << e.what() << std::endl; }
    delete form;
    form = NULL;
    
    std::cout << GREEN << "\n== Signature Test " << RESET << std::endl;
    form = someIntern.makeForm("presidential pardon", "Target");
    if (form)
    {
        Bureaucrat weakling("Weakling", 150);
        weakling.signForm(*form);
        if (form->getSignStatus())
            weakling.executeForm(*form);
        else
            std::cout << "Form not signed, skipping execution (expected)" << std::endl;
        delete form; 
        form = NULL;
    }

    std::cout << GREEN << "\n== Execution Test" << RESET << std::endl;
    form = someIntern.makeForm("robotomy request", "HAL");
    if (form)
    {
        try {
            Bureaucrat exec("Exec", 1);
            exec.executeForm(*form);}
        catch(std::exception & e){
            std::cerr << RED << e.what() << RESET << std::endl;
        }
        delete form; 
        form = NULL;
    }

    std::cout << GREEN << "\n== More Tests ==" << RESET << std::endl;
    try {
        form = someIntern.makeForm("presidential pardon", "Charlie");
        Bureaucrat signer("Signer", 1);
        signer.signForm(*form);
        Bureaucrat tooLow("TooLow", 100);
        tooLow.executeForm(*form);
        delete form; 
        form = NULL;
    }
    catch(Intern::UnknownForm & e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    delete form;
    form = NULL;
    return 0;
}