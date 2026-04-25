#ifndef RPN_HPP
#define RPN_HPP

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

class RPN {
    private:
        std::stack<int> _data;
    public:
        RPN();
        RPN(const RPN & src);
        ~RPN();
        RPN &operator=(const RPN &src);

        void calculate(std::string input);
};

#endif