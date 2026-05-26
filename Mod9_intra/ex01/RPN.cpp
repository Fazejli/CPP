#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN & src){
    this->_data = src._data;
}
        
RPN::~RPN(){}
        
RPN &RPN::operator=(const RPN &src){
    if (this != &src)
        this->_data = src._data;
    return *this;
}

int operations(int first, int sec, char op){
    if (op == '-')
        return (first - sec);
    else if (op == '+')
        return (first + sec);
    else if (op == '*')
        return (first * sec);
    else {
        if (sec == 0)
            throw std::runtime_error("Error: impossible division by 0");
        return (first / sec);}
}

void RPN::calculate(std::string input){
    char tokens[5] = {
        '*',
        '-',
        '+',
        '/',
        ' '
    };
    char op;
    int res;
    int i = 0;
    while (input[i])
    {
        int j = 0;
        while (j < 5){
            if (input[i] == tokens[j])
                break ;
            j++;
        }
        if (j == 4){
            i++;
            continue;}
        //operateur
        if (j <= 3){
            op = tokens[j];
            if (_data.size() < 2){
                std::cerr << RED << "Error: invalid input(size)" << RESET << std::endl;
                return ;}
            try {
                int sec = _data.top();
                _data.pop();
                int first = _data.top();
                _data.pop();
                res = operations(first, sec, op);
                _data.push(res);}
            catch (std::exception &e){
                std::cerr << e.what() << std::endl;
                return ;
            }
        }
        else if (input[i] >= '0' && input[i] <= '9'){
            if (input[i+1] >= '0' && input[i+1] <= '9'){
                std::cerr << RED << "Error: invalid input(digit)" << RESET << std::endl;
                return ;}
            _data.push(input[i] - '0');
        }
        else{
            std::cerr << RED << "Error." << RESET << std::endl;
            return ;
        }
        i++;
    }
    if (_data.size() != 1){
        std::cerr << RED << "Error: Usage: ./RPN \"8 9 * 9 - 1 + 2\"" << RESET << std::endl;
        return ;}
    std::cout << _data.top() << std::endl;
}
