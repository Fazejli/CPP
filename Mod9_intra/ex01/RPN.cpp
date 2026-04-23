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
    else
        return (first / sec);
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
            if (_data.size() != 2){
                std::cerr << RED << "Error: invalid input" << RESET << std::endl;
                return ;}
            else{
                res = operations(_data.top(), _data.top(), op);
                _data.pop();
                _data.pop();
                _data.push(res);}
        }
        //digit push to _data
        else if (input[i] >= '0' && input[i] <= '9'){
            if (input[i+1] >= '0' && input[i+1] <= '9'){
                std::cerr << RED << "Error: invalid input" << RESET << std::endl;
                return ;}
            _data.push(input[i] - '0');
        }
        //invalid
        else{
            std::cerr << RED << "Error: invalid input" << RESET << std::endl;
            return ;
        }
        i++;
    }
    std::cout << res << std::endl;
}
