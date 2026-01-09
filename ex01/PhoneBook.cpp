#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    contactIndex = 0;
}

void    PhoneBook::addContact(){
    std::string input;
    Contact newContact;

    std::cout << "First Name: ";
    std::getline(std::cin, input);
    if (input.empty())
        return ;
    newContact.setFirstName(input);

    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    if (input.empty())
        return ;
    newContact.setLastName(input);

    std::cout << "Nick Name: ";
    std::getline(std::cin, input);
    if (input.empty())
        return ;
    newContact.setNickName(input);

    std::cout << "Phone number: ";
    std::getline(std::cin, input);
    if (input.empty())
        return ;
    newContact.setPhoneNumber(input);

    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    if (input.empty())
        return ;
    newContact.setDarkestSecret(input);

    contacts[contactIndex] = newContact;
    contactIndex += 1; 
    if (contactIndex % 8 == 0)
        contactIndex = 0;
    //contactIndex = contactIndex+1 % 8;
}

void    PhoneBook::displayAllContacts(){
    int index(0);

    while (index < contactIndex)
    {
        std::cout << "Number"
    }
}

void    PhoneBook::displayContact(int index){

}
