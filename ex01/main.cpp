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
        if (input == "ADD")
            phonebook.addContact();
        if (input == "SEARCH")
        {
            phonebook.displayAllContacts();
            std::cin >> index;
            if (index <= 0 || index >= 8)
            {
                std::cout << "Uknown." << std::endl;
                return (0);
            }
            index -= 1;
            phonebook.displayContact(index);
        }
        if (input == "EXIT")
            break ;
    }
    return (1);
}
