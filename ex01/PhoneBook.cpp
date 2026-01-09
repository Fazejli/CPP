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

    currentContact = contacts[index];
    if (index == 8 || currentContact.getFirstName().empty())
    {
        std::cout << "Non existent contact." << std::endl;
        return ;
    }
    std::cout << std::setfille(' ') << std::endl;
    std::cout << "Index: " << std::setw(10) << index << '|';
    std::cout << "First Name: " << std::setw(10) << truncate(currentContact.getFirstName()) << '|';
    std::cout << "Last Name: " << std::setw(10) << truncate(currentContact.getLastName()) << '|';
    std::cout << "Nickname: " << std::setw(10) << truncate(currentContact.getNickName()) << '|';
    std::cout << "Phone Number: " << std::setw(10) << truncate(currentContact.getPhoneNumber()) << '|';
    std::cout << "Darkest Secret: " << std::setw(10) << truncate(currentContact.getDarkestSecret()) << std::endl;
}

void    PhoneBook::displayAllContacts(){
    Contact currentContact;
    int     index;

    index = 0;
    currentContact = contacts[index];
    std::cout << std::setw(10) << "Index" << '|';
    std::cout << std::setw(10) << "First Name" << '|';
    std::cout << std::setw(10) << "Last Name" << '|';
    std::cout << std::setw(10) << "Nickname" << std::endl;
    while (index < 8)
    {
        if (currentContact.getFirstName().empty())
            break ;
        std::cout << std::setfille(" ") << endl;
        std::cout << std::setw(10) << index << '|';
        std::cout << std::setw(10) << truncate(currentContact.getFirstName()) << '|';
        std::cout << std::setw(10) << truncate(currentContact.getLastName()) << '|';
        std::cout << std::setw(10) << truncate(currentContact.getNickName()) << std::endl;
        index++;
    }
}