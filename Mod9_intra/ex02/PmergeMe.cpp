#include "PmergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::~PMergeMe(){}

PMergeMe::PMergeMe(const PMergeMe &othr) : _vec(othr._vec), _deq(othr._deq){}
        
PMergeMe &PMergeMe::operator=(const PMergeMe &src){
    if (this != &src){
        this->_vec = src._vec;
        this->_deq = src._deq;
    }
    return (*this);
}

void PMergeMe::sortDequ(std::deque<int> &src){
    if (src.size() <= 1)
        return ;
    bool hasStraggler = (src.size() % 2 != 0); //true if has straggler;
    int straggler = src[src.size()-1];

    std::vector<std::pair<int,int> > pairs;
    for(size_t i = 0; i+1 < src.size(); i+=2){
        int a = src[i];
        int b = src[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    std::deque<int> winners;
    std::deque<int> losers;
    for(size_t i = 0; i < pairs.size(); i++){
        winners.push_back(pairs[i].second);
        losers.push_back(pairs[i].first);
    }
    sortDequ(winners);
    std::deque<int> losers_ordered;
    for (size_t i = 0; i < winners.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == winners[i]) {
                losers_ordered.push_back(pairs[j].first);
                break;
            }
        }
    }
    losers = losers_ordered;
    std::deque<int> result;
    result.push_back(losers[0]);
    for (size_t i = 0; i < winners.size(); i++)
        result.push_back(winners[i]);
   
    std::vector<int> jac = jacobsthal(losers.size());
    std::deque<bool> inserted(losers.size(), false);
    for (size_t k = 1; k < jac.size(); k++) {
        int idx = jac[k] - 1;  // converti en index 0-based
        if (idx >= (int)losers.size())
            idx = losers.size() - 1;
        // insère de idx jusqu'à jac[k-1] en descendant
        for (int j = idx; j >= jac[k-1]; j--) {
            if (j <= 0 || inserted[j]) continue;
            std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), losers[j]);
            result.insert(it, losers[j]);
            inserted[j] = true;
        }
    }

    if (hasStraggler){
        std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(it, straggler);
    }
    src = result;
}

void PMergeMe::sortVect(std::vector<int> &src){
    if (src.size() <= 1)
        return ;
    bool hasStraggler = (src.size() % 2 != 0); //true if has straggler;
    int straggler = src[src.size()-1];

    std::vector<std::pair<int,int> > pairs;
    for(size_t i = 0; i+1 < src.size(); i+=2){
        int a = src[i];
        int b = src[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    std::vector<int> winners;
    std::vector<int> losers;
    for(size_t i = 0; i < pairs.size(); i++){
        winners.push_back(pairs[i].second);
        losers.push_back(pairs[i].first);
    }
    sortVect(winners);
    std::vector<int> losers_ordered;
    for (size_t i = 0; i < winners.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == winners[i]) {
                losers_ordered.push_back(pairs[j].first);
                break;
            }
        }
    }
    losers = losers_ordered;
    std::vector<int> result;
    result.push_back(losers[0]);
    for (size_t i = 0; i < winners.size(); i++)
        result.push_back(winners[i]);

    std::vector<int> jac = jacobsthal(losers.size());
    std::vector<bool> inserted(losers.size(), false);
    for (size_t k = 1; k < jac.size(); k++) {
        int idx = jac[k] - 1;
        if (idx >= (int)losers.size())
            idx = losers.size() - 1;
        for (int j = idx; j >= jac[k-1]; j--) {
            if (j <= 0 || inserted[j]) continue;
            std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), losers[j]);
            result.insert(it, losers[j]);
            inserted[j] = true;}}
        
    if (hasStraggler){
        std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(it, straggler);
    }
    src = result;
}


void PMergeMe::run(int ac, char **av){
    int i = 1;
    while (i < ac){
        std::istringstream ss(av[i]);
        std::string token;
        while (ss >> token){
            try {
                for(size_t j = 0; token[j] != '\0'; j++){
                    if (token[j] == '-')
                        throw std::invalid_argument("Error: not a positive number");
                    if (!isdigit(token[j]))
                        throw std::out_of_range("Error: not a valid number");
                }
                long nb = std::atol(token.c_str());
                if (nb <= 0 || nb > INT_MAX)
                    throw std::out_of_range("Error: overflow");
                _vec.push_back(static_cast<int>(nb));
                _deq.push_back(static_cast<int>(nb));
            }
            catch (std::exception & e) {
                std::cerr << e.what() << std::endl;
                return ;
            }}
        i++;
    }
    std::cout << "Before: ";
    print(_vec);
    clock_t start = clock();
    this->sortVect(_vec);
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    print(_vec);

    std::cout << "Time to process a range of " << _vec.size();
    std::cout << " elements with std::vect : ";
    std::cout << std::fixed << std::setprecision(2) << time << " us\n";

    start = clock();
    this->sortDequ(_deq);
    end = clock();
    time = double(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << _deq.size();
    std::cout << " elements with std::deque : ";
    std::cout << std::fixed << std::setprecision(2) << time << " us\n";
}

void PMergeMe::print(const std::vector<int> &src) const{
    std::vector<int>::const_iterator it = src.begin();
    std::vector<int>::const_iterator it_last = src.end();
    while (it < it_last){
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

std::vector<int> PMergeMe::jacobsthal(int n) {
    std::vector<int> seq;
    seq.push_back(0);
    seq.push_back(1);
    while (seq.back() < n) {
        int sz = seq.size();
        seq.push_back(seq[sz - 1] + 2 * seq[sz - 2]);
    }
    return seq;
}