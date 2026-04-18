#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::Serializer(const Serializer & src){(void)src;}
Serializer::~Serializer(){}
Serializer &Serializer::operator=(const Serializer & src){(void)src; return *this;}

uintptr_t Serializer::serialize(Data *ptr){
    std::cout << CYAN << "Successfull Serialization." << RESET << std::endl;
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
    std::cout << CYAN << "Successfull Deserialization." << RESET << std::endl;
    return (reinterpret_cast<Data*>(raw));
}
