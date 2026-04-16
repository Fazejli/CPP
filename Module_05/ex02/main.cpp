#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>


int main(){
    std::srand(std::time(NULL));

    std::cout << GREEN << "== Basic Test: ShrubberyCreationForm ==" << RESET << std::endl;
    try {
        ShrubberyCreationForm shrub("home");
        Bureaucrat gardener("Gardener", 136);
        std::cout << gardener << std::endl;
        std::cout << shrub << std::endl;
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
    }
    catch (const std::exception &e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n== Basic Test: RobotomyRequestForm ==" << RESET << std::endl;
    try {
        Bureaucrat surgeon("Surgeon", 45);
        RobotomyRequestForm robot("Alien");
        std::cout << surgeon << std::endl;
        std::cout << robot << std::endl;

        surgeon.signForm(robot);
        surgeon.executeForm(robot);
        surgeon.executeForm(robot);
        surgeon.executeForm(robot);
        surgeon.executeForm(robot);
    }
    catch (const std::exception &e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n== Basic Test: PresidentialPardonForm ==" << RESET << std::endl;
    try {
        PresidentialPardonForm pardon("Trump");
        Bureaucrat president("Obama", 2);
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (const std::exception &e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n== Form Exec Test ==" << RESET << std::endl;
    try {
        ShrubberyCreationForm shrub2("toto");
        Bureaucrat lazy("Lazy", 1);
        //lazy.signForm(shrub2);
        lazy.executeForm(shrub2);
    }
    catch (const std::exception &e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n== Error Tests: Execution error ==" << RESET << std::endl;
    try {
        PresidentialPardonForm pardon2("Charlie");
        Bureaucrat t("Trump", 1);
        t.signForm(pardon2);
        Bureaucrat tooLow("TooLow", 100);
        tooLow.executeForm(pardon2);
    }
    catch (const std::exception &e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return (0);
}