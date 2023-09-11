/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:37:38 by sbhatta           #+#    #+#             */
/*   Updated: 2023/09/11 18:57:20 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    
}

PhoneBook::~PhoneBook()
{
    
}

void PhoneBook::setContact(int index)
{
    std::cout << "Enter First Name: ";
    _contactArray[index].setVar("fname");
    std::cout << "Enter Last Name: ";
    _contactArray[index].setVar("lname");
    std::cout << "Enter Nickname: ";
    _contactArray[index].setVar("nname");
    std::cout << "Enter Phone Number: ";
    _contactArray[index].setVar("pnum");
    std::cout << "Enter Your Darkest Secrets: ";
    _contactArray[index].setVar("dsecr");
}

void PhoneBook::getContact( )
{
    int entered;
    
    for(int index = 0; index < 8; index++)
    {
        std::cout << "First Name: " << _contactArray[index].getVar("fname") << std::endl;
        std::cout << "Last Name: " << _contactArray[index].getVar("lname") << std::endl;
        std::cout << "Nickname: " << _contactArray[index].getVar("nname") << std::endl;
        std::cout << "Phone Number: " << _contactArray[index].getVar("pnum") << std::endl;
        std::cout << "Dark Secrets: " << _contactArray[index].getVar("dsecr") << std::endl << std::endl;
    }
    std::cout << "Enter Index: ";
    std::cin >> entered;
    if (entered >= 0 && entered <= 8)
    {
        std::cout << "First Name: " << _contactArray[entered - 1].getVar("fname") << std::endl;
        std::cout << "Last Name: " << _contactArray[entered - 1].getVar("lname") << std::endl;
        std::cout << "Nickname: " << _contactArray[entered - 1].getVar("nname") << std::endl;
        std::cout << "Phone Number: " << _contactArray[entered - 1].getVar("pnum") << std::endl;
        std::cout << "Dark Secrets: " << _contactArray[entered - 1].getVar("dsecr") << std::endl << std::endl;
    }
    else
        std::cout << "Entered index is out of scope. Please try again!" << std::endl;
}

void PhoneBook::printWelcome( void )
{
    std::cout << "ADD: save a new contact" << std::endl;
    std::cout << "SEARCH: display a specific contact" << std::endl;
    std::cout << "EXIT: The program quits and the contacts are lost forever!" << std::endl;
}

int PhoneBook::checkCommand(int index)
{
    std::string cmd;

    std::cout << "Enter Command: ";
    std::cin >> cmd;
    if (cmd == "ADD")
    {
        setContact(index);
        return (1);
    }
    else if (cmd == "SEARCH")
    {
        getContact();
        return (0);
    }
    else if (cmd == "EXIT")
        exit (0);
    return (0);
}