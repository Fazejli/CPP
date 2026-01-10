#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook{
    private:
    Contact         contacts[8];
    int             contactIndex;
    std::string truncate(std::string str);
   
    public:
    PhoneBook();
    void    addContact();
    void    displayAllContacts();
    void    displayContact(int index);
};

#endif