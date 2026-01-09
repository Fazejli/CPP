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

std::string PhoneBook::truncate(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void    PhoneBook::displayContact(int index){
    Contact currentContact;

    if (index < 0 || index >= 8)
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }   
    currentContact = contacts[index];
    if (currentContact.getFirstName().empty())
    {
        std::cout << "Non existent contact." << std::endl;
        return ;
    }
    std::cout << "First Name: " << currentContact.getFirstName() << std::endl;
    std::cout << "Last Name: " << currentContact.getLastName() << std::endl;
    std::cout << "Nickname: " << currentContact.getNickName() << std::endl;
    std::cout << "Phone Number: " << currentContact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << currentContact.getDarkestSecret() << std::endl;
}

void    PhoneBook::displayAllContacts(){
    Contact currentContact;
    int     index;

    index = 0;
    std::cout << std::setw(10) << "Index" << '|';
    std::cout << std::setw(10) << "First Name" << '|';
    std::cout << std::setw(10) << "Last Name" << '|';
    std::cout << std::setw(10) << "Nickname" << std::endl;
    while (index < 8)
    {
        currentContact = contacts[index];
        if (currentContact.getFirstName().empty())
            break ;
        std::cout << std::setfill(' ');
        std::cout << std::setw(10) << index << '|';
        std::cout << std::setw(10) << truncate(currentContact.getFirstName()) << '|';
        std::cout << std::setw(10) << truncate(currentContact.getLastName()) << '|';
        std::cout << std::setw(10) << truncate(currentContact.getNickName()) << std::endl;
        index++;
    }
}