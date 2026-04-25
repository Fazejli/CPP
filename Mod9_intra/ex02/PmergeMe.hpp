#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>

class PMergeMe {
    public:
        PMergeMe();
        ~PMergeMe();
        PMergeMe(const PMergeMe &othr);
        PMergeMe &operator=(const PMergeMe &src);
        void run(int ac, char **av);

    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

        std::vector<int> jacobsthal(int n);
        void sortVect(std::vector<int> &src);
        void sortDequ(std::deque<int> &src);
        void print(const std::vector<int> &src) const;
};

#endif