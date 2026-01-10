#include "Zombie.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: randomChump (STACK) ===" << std::endl;
    randomChump("StackZombie");
    std::cout << "randomChump terminé\n" << std::endl;
    
    std::cout << "=== Test 2: newZombie (HEAP) ===" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    std::cout << "HeapZombie existe toujours" << std::endl;
    delete heapZombie;
    std::cout << "HeapZombie supprimé\n" << std::endl;
    
    std::cout << "=== Test 3: Plusieurs zombies ===" << std::endl;
    Zombie* z1 = newZombie("Charlie");
    Zombie* z2 = newZombie("Diana");
    
    z1->announce();
    z2->announce();
    
    delete z1;
    delete z2;
    
    return 0;
}