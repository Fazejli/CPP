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

void PMergeMe::sortVect(std::vector<int> &src){
    if (src.size() <= 1)
        return ;

    bool hasStraggler = (src.size() % 2 != 0);
    int straggler = hasStraggler ? src[src.size() - 1] : 0;

    std::vector<std::pair<int,int> > pairs;
    for (size_t i = 0; i + 1 < src.size(); i += 2){
        int a = src[i];
        int b = src[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b)); // (loser, winner)
    }

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); i++)
        winners.push_back(pairs[i].second);
    sortVect(winners);

    std::vector<bool> used(pairs.size(), false);
    std::vector<int> losers;
    for (size_t i = 0; i < winners.size(); i++){
        for (size_t j = 0; j < pairs.size(); j++){
            if (!used[j] && pairs[j].second == winners[i]){
                losers.push_back(pairs[j].first);
                used[j] = true;
                break;
            }
        }
    }

    std::vector<int> result;
    result.push_back(losers[0]);
    for (size_t i = 0; i < winners.size(); i++)
        result.push_back(winners[i]);

    std::vector<int> jac = jacobsthal(losers.size());

    std::vector<bool> inserted(losers.size(), false);
    inserted[0] = true;

    for (size_t k = 1; k < jac.size(); k++){
        int idx = jac[k] - 1;
        if (idx >= (int)losers.size())
            idx = (int)losers.size() - 1;
        int prev = jac[k - 1] - 1;
        if (prev < 0) prev = 0;
        for (int j = idx; j >= prev; j--){
            if (j < 0 || inserted[j]) continue;
            std::vector<int>::iterator it =
                std::lower_bound(result.begin(), result.end(), losers[j]);
            result.insert(it, losers[j]);
            inserted[j] = true;
        }
    }

    if (hasStraggler){
        std::vector<int>::iterator it =
            std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(it, straggler);
    }
    src = result;
}

void PMergeMe::sortDequ(std::deque<int> &src){
    if (src.size() <= 1)
        return ;

    bool hasStraggler = (src.size() % 2 != 0);
    int straggler = hasStraggler ? src[src.size() - 1] : 0;

    std::vector<std::pair<int,int> > pairs;
    for (size_t i = 0; i + 1 < src.size(); i += 2){
        int a = src[i];
        int b = src[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); i++)
        winners.push_back(pairs[i].second);
    sortDequ(winners);

    std::vector<bool> used(pairs.size(), false);
    std::deque<int> losers;
    for (size_t i = 0; i < winners.size(); i++){
        for (size_t j = 0; j < pairs.size(); j++){
            if (!used[j] && pairs[j].second == winners[i]){
                losers.push_back(pairs[j].first);
                used[j] = true;
                break;
            }
        }
    }

    std::deque<int> result;
    result.push_back(losers[0]);
    for (size_t i = 0; i < winners.size(); i++)
        result.push_back(winners[i]);

    std::vector<int> jac = jacobsthal(losers.size());

    std::vector<bool> inserted(losers.size(), false);
    inserted[0] = true;
    for (size_t k = 1; k < jac.size(); k++){
        int idx = jac[k] - 1;
        if (idx >= (int)losers.size())
            idx = (int)losers.size() - 1;
        int prev = jac[k - 1] - 1;
        if (prev < 0) prev = 0;
        for (int j = idx; j >= prev; j--){
            if (j < 0 || inserted[j]) continue;
            std::deque<int>::iterator it =
                std::lower_bound(result.begin(), result.end(), losers[j]);
            result.insert(it, losers[j]);
            inserted[j] = true;
        }
    }

    if (hasStraggler){
        std::deque<int>::iterator it =
            std::lower_bound(result.begin(), result.end(), straggler);
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
                for (size_t j = 0; token[j] != '\0'; j++){
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
            catch (std::exception &e){
                std::cerr << e.what() << std::endl;
                return ;
            }
        }
        i++;
    }

    std::cout << "Before: ";
    print(_vec);

    clock_t start = clock();
    this->sortVect(_vec);
    clock_t end = clock();
    double timeVec = double(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After:  ";
    print(_vec);

    std::cout << "Time to process a range of " << _vec.size();
    std::cout << " elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(2) << timeVec << " us\n";

    start = clock();
    this->sortDequ(_deq);
    end = clock();
    double timeDeq = double(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _deq.size();
    std::cout << " elements with std::deque  : ";
    std::cout << std::fixed << std::setprecision(2) << timeDeq << " us\n";
}

void PMergeMe::print(const std::vector<int> &src) const {
    for (std::vector<int>::const_iterator it = src.begin(); it != src.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}