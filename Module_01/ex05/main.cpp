#include "Harl.hpp"

int main(void) {
    Harl harl;
    
    std::cout << "========================================" << std::endl;
    std::cout << "  TEST 1: Basic tests" << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::cout << "\n--- [ DEBUG ] ---" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\n--- [ INFO ] ---" << std::endl;
    harl.complain("INFO");
    
    std::cout << "\n--- [ WARNING ] ---" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "\n--- [ ERROR ] ---" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "  TEST 2: Niveau invalide" << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::cout << "\n--- Nonexistent level: CRITICAL ---" << std::endl;
    harl.complain("CRITICAL");
    
    std::cout << "\n--- Lowercase : debug ---" << std::endl;
    harl.complain("debug");
    
    std::cout << "\n--- Empty string ---" << std::endl;
    harl.complain("");
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "  TEST 3: Plusieurs appels successifs" << std::endl;
    std::cout << "========================================" << std::endl;
    
    harl.complain("ERROR");
    harl.complain("ERROR");
    harl.complain("ERROR");
    harl.complain("WARNING");
    harl.complain("DEBUG");
    harl.complain("WARNING");
    harl.complain("INFO");

    return 0;
}