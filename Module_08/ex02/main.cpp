#include "MutantStack.hpp"
#include <list>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

int main(){
    MutantStack<int> m;
    int nb = 1;
    for (int i = 0; i < 10; i++)
        m.push(nb++);

    std::cout << GREEN << "== Basic std:stack methods test ==" << RESET << std::endl;
    if (!m.empty()){
        std::cout << "MutantStack m is not empty." << std::endl;
        std::cout << "Data size = " << m.size() << std::endl;
        std::cout << "Data at first/top element: " << m.top() << std::endl;
        m.pop();
        std::cout << "Data size after pop(): " << m.size() << std::endl;
        std::cout << CYAN << "Printing...\t" << RESET;
        MutantStack<int>::iterator first_it = m.begin();
        MutantStack<int>::iterator last_it = m.end();
        while (first_it != last_it)
            std::cout << *first_it++ << " ";
        first_it = m.begin();
        std::cout << "\nm[0] = " << *first_it << std::endl;
        first_it++;
        std::cout << "m[1] = " << *first_it << std::endl;
        last_it--;
        std::cout << "m[size - 1] = " << *last_it << std::endl;
    }

    std::cout << GREEN << "\n== Alphabet test ==" << RESET << std::endl;
    MutantStack<char> alpha;
    char c = 'a';
    for (int j = 0; j < 26; j++)
        alpha.push(c++);
    if (alpha.empty()){
        std::cout << "Empty MutantStack" << std::endl;
        return 1;}
    const MutantStack<char>::iterator const_first = alpha.begin();
    const MutantStack<char>::iterator const_last = alpha.end();
    MutantStack<char>::iterator first = alpha.begin();
    MutantStack<char>::iterator last = alpha.end();
    --last;
    std::cout << "MutantStack alpha has " << YELLOW << alpha.size() << RESET << " letters." << std::endl;
    std::cout << "The Alphabet alpha starts with " << YELLOW << *const_first << RESET;
    std::cout << " and ends with " << YELLOW << *last << RESET << std::endl;
    std::cout << MAGENTA << "Let's print the whole Alphabet: " << RESET << std::endl;
    while (first != const_last){
        std::cout << *first << " ";
        ++first;}
    std::cout << "." << std::endl;
    return (0);
}

/*int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n== Comparison with std::list ==" << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator b = mlist.begin();
    std::list<int>::iterator e = mlist.end();

    ++b;
    --b;
    while (b != e)
    {
        std::cout << *b << std::endl;
        ++b;
    }
    return 0;}*/

    