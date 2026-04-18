#include "Serializer.hpp"

int main()
{
    std::cout << GREEN << "== Basic test ==" << std::endl;

    uintptr_t res;
    Data *ptr = new struct t_data[2];
    ptr->nbr = 10;
    res = Serializer::serialize(ptr);

    Data *result = Serializer::deserialize(res);

    if (result == ptr)
        std::cout << "SUCCESS" << std::endl;
    else
        std::cerr << "FAIL" << std::endl;

    delete[] ptr;
    return (0);
}