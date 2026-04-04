#include "Harl.hpp"


Harl::Harl(void){
}

Harl::~Harl(void){
}

void Harl::complain(std::string level){
    int i(0);
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void(Harl::*ftPtr[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    while (i < 4)
    {
        if (levels[i] == level)
            break ;
        i++;
    }
    if (i < 4)
        (this->*ftPtr[i])();
    else
        std::cout << "Non existent level.";
}

void Harl::debug( void ){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my";
    std::cout << " 7XL-double-cheese-triple-pickle-specialketchup burger.";
    std::cout << " I really do!" << std::endl;
}

void Harl::info( void ){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money.";
    std::cout << " You didn’t put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void ){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I’ve been coming for years, whereas you started working here just last month.";
    std::cout << std::endl;
}

void Harl::error( void ){
    std::cout << "[ ERROR ]" << std::endl;
    std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
