#include "Serializer.hpp"
#include <iostream>

int main(){
    std::cout << GREEN << "Testing match.." << RESET << std::endl;

    Data *ptr = new Data[2];
    ptr[0].nbr = 10;
    ptr[0].name = "bob";

    uintptr_t res = Serializer::serialize(ptr);
    Data *result = Serializer::deserialize(res);

    if (result == ptr && result->nbr == ptr[0].nbr && result->name == ptr[0].name){
        std::cout << MAGENTA << "SUCCESS: Pointer match" << RESET << std::endl;
        std::cout << "Nbr = " << CYAN << result->nbr << RESET;
        std::cout << " & Name = " << CYAN << result->name << RESET << std::endl;}
    else{
        std::cerr << RED << "FAIL:" << RESET << "generated ptr =" << (result == ptr) << ", nbr =" << result->nbr;
        std::cout << " & name = " << result->name << std::endl;
    }
    delete[] ptr;
    return (0);
}
