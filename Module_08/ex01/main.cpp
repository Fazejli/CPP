#include "Span.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    Span sp = Span (6);

    std::cout << GREEN << "== Basic Test ==" << RESET << std::endl;
    try {
        sp.addNumber(21);
        sp.addNumber(1);
        sp.addNumber(6);
        sp.addNumber(100);
        sp.addNumber(3);
        std::cout << "sp shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "sp longestSpan: " << sp.longestSpan() << std::endl;
    } catch(std::exception & e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << GREEN << "\n== Error Test: addNumber() exception" << RESET << std::endl;
    try {
        sp.addNumber(0);
        std::cout << "new nb" << std::endl;
        sp.addNumber(42);
    } catch(std::exception & e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n== SPAN Test: shortestSpan() && longestSpan() ==" << RESET << std::endl;
    try {
        Span sp2(1);
        sp2.addNumber(0);
        std::cout << "sp shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "sp longestSpan: " << sp.longestSpan() << std::endl;
        std::cout << "sp2 shortestSpan: " << sp2.shortestSpan() << std::endl;
        //std::cout << "sp2 longestSpan: " << sp2.longestSpan() << std::endl;
    }
    catch(std::exception &e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n== More tests ==" << RESET << std::endl;
    std::vector<int> range;
    for (int i = 0; i < 10000; i++)
        range.push_back(rand());

    Span large(10000);
    try {
        large.addRange(range.begin(), range.end());
        std::cout << "ShortestSpan: " << large.shortestSpan() << std::endl;
        std::cout << "LongestSpan: " << large.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    return 0;
}

/*
int main(){
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0
}*/