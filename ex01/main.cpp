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
        std::cin.ignore(input);
        if (input == "ADD")
            addContact();
        if (input == "SEARCH")
        {
            displayAllContacts();
            std::cin.ignore(index);
            if (index <= 0 || index >= 8)
            {
                std::cout << "Uknown." << std::endl;
                return (0);
            }
            index -= 1;
            displayContact(index);
        }
        if (input == EXIT)
            break ;
    }
    return (1);
}
