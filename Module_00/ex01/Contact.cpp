#include "Contact.hpp"

Contact::Contact() {
}

void Contact::setFirstName(std::string name) {
    firstName = name;
}

void Contact::setLastName(std::string last) {
    lastName = last;
}

void Contact::setDarkestSecret(std::string secret) {
    darkestSecret = secret;
}

void Contact::setPhoneNumber(std::string number) {
    phoneNumber = number;
}

void Contact::setNickName(std::string pseudo) {
    nickName = pseudo;
}

std::string Contact::getDarkestSecret() const {
    return (darkestSecret);
}

std::string Contact::getFirstName() const {
    return (firstName);
}

std::string Contact::getLastName() const {
    return (lastName);
}

std::string Contact::getPhoneNumber() const {
    return (phoneNumber);
}
std::string Contact::getNickName() const {
    return (nickName);
}