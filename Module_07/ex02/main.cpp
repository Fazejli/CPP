#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

template <typename T>
void print(const T& x) {
    std::cout << x << "  ";
}

template <typename T, typename F>
void iter(T *a, const int size, F f){
    for (int i(0); i < size; i++)
            f(a[i]);
}

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << GREEN << "== Basic test == " << RESET << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    int value = numbers.size();
    for (int i = 0; i < value; i++)
        numbers[i] = i;
    for (int i = 0; i < MAX_VAL; i++)
        mirror[i] = i;
    std::cout << "Array size = " << numbers.size() << std::endl;
    std::cout << CYAN << "Printing array.." << RESET << std::endl;
    std::cout << "mirror[] = ";
    iter(mirror, MAX_VAL, print<int>);
    
    std::cout << CYAN << "\n//changing mirror[] values... " << RESET << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        mirror[i] = value--;
    std::cout << "mirror[] = ";
    iter(mirror, MAX_VAL, print<int>);

    std::cout << GREEN << "\n\n== Test: Add out of bounds value == " << RESET << std::endl;
    try{
        numbers[0] = 42;
        std::cout << "numbers[0] modified" << std::endl;
        numbers[MAX_VAL + 1] = 15;
    }
    catch(std::exception & e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n== Test: operator[] && operator!= == " << RESET << std::endl;
    std::cout << CYAN << "//Compare values" << RESET << std::endl;
    mirror[0] = 42;
    for (int i = 0; i < MAX_VAL; i++){ 
        if (numbers[i] == mirror[i])
            std::cout << "Same value: " << numbers[i] << std::endl;
        else
            std::cout << "Different value" << std::endl;
    }
    std::cout << CYAN << "\nCompare lists" << RESET << std::endl;
    Array<int> nb(MAX_VAL);
    for (int i = 0; i < MAX_VAL; i++)
        nb[i] = numbers[i];
    if (numbers != nb)
        std::cout << "Different list" << std::endl;
    else
        std::cout << "Same list" << std::endl;
    delete[] mirror;
    return 0;
}

/*int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}*/