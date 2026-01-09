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
    contactIndex = (contactIndex + 1) % 8;
}

void    PhoneBook::displayAllContacts(){
    Contact newContact;
    int     index;

    index = 0;
    std::cout << setfill('.') << std::endl;
    std::cout << setw(10) << "index" << '|';
    std::cout << setw(10) << "First Name" << '|';
    std::cout << setw(10) << "Last Name" << '|';
    std::cout << setw(10) << "Nickname" << std::endl;
    while (index != 8)
    {
        displayContact(index);
        index++;
    }
}

void    PhoneBook::displayContact(int index){
    Contact currentContact;

    currentContact = contacts[index];
    if (index == 8 || currentContact.getFirstNameirstName().empty())
    {
        std::cout << "Non existent contact." << std::endl;
        return ;
    }
    std::cout << setw(10) << index << '|';
    std::cout << setw(10) << currentContact.getFirstName() << '|';
    std::cout << setw(10) << currentContact.getLastName() << '|';
    std::cout << setw(10) << currentContact.getNickName() << std::endl;
}
