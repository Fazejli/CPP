#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <fstream>
#include <stdint.h>

typedef struct t_data{
    uintptr_t nbr;
}   Data;

class Serializer{
    private:
        Serializer();
        Serializer(const Serializer & src);
        ~Serializer();
        Serializer &operator=(const Serializer & src);
    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
        
};

#endif