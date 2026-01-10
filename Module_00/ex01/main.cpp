#include "PhoneBook.hpp"
#include "Contact.hpp"


int main(int ac, char **av)
{
    PhoneBook phonebook;
    std::string input;
    int         index;

    while (1)
    {
        std::cout << "Enter a command: " << std::endl;
        std::getline(std::cin, input);
        if (std::cin.eof())
            break ;
        if (input == "ADD")
            phonebook.addContact();
        else if (input == "SEARCH")
        {
            phonebook.displayAllContacts();
            std::cin >> index;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input." << std::endl;
            }
            else
            {
                std::cin.ignore(10000, '\n');
                phonebook.displayContact(index);
            }
        }
        if (input == "EXIT")
            break ;
    }
    return (1);
}
