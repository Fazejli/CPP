#include "PhoneBook.hpp"
#include "Contact.hpp"


int main(int ac, char **av)
{
    (void)ac;
    void(av);
    std::string input;
    int         index;

    while (1)
    {
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
