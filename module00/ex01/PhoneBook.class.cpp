/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:58:20 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/09 17:23:36 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
	_oldest = 0;
	std::cout << "Contact constructor called." << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Contact destructor called." << std::endl;
	return;
}

void    PhoneBook::setContact(void) {
	std::string fName;
	std::string lName;
	std::string nName;
	std::string pNum;
	std::string dSec;

	std::cout << "First name: ";
	getline(std::cin, fName);
	std::cout << "Last name: ";
	getline(std::cin, lName);
	std::cout << "Nickname: ";
	getline(std::cin, nName);
	std::cout << "Phone Number: ";
	getline(std::cin, pNum);
	std::cout << "Darkest secret: ";
	getline(std::cin, dSec);
	size_t	i = -1;
	while (++i < 8)
	{
		if (_cList[i].isEmpty())
		{
			_cList[i] = Contact(fName, lName, nName, pNum, dSec);
			break ;
		}
	}
	if (i == 8)
	{
		if (_oldest == 8)
			_oldest = 0;
		_cList[_oldest] = Contact(fName, lName, nName, pNum, dSec);
		_oldest++;
	}
}

void    PhoneBook::getList(void) const {
	std::cout << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::setw(10) << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	size_t	i = -1;
	while (!_cList[++i].isEmpty() && i < 8)
	{
		std::cout << std::setw(10) << i;
		std::cout << "|";
		if (_cList[i].firstName.length() > 10)
			std::cout << std::setw(10) << _cList[i].firstName;
		else
			std::cout << std::setw(10) << _cList[i].firstName;
		std::cout << "|";
		std::cout << std::setw(10) << _cList[i].lastName;
		std::cout << "|";
		std::cout << std::setw(10) << _cList[i].nickname << std::endl;
	}
}

void    PhoneBook::getContact(int index) const {
	if (index < 0)
	{
		std::cout << "Wrong input." << std::endl;
		return;
	}
	if (_cList[index].isEmpty())
	{
		std::cout << "No Contact found on index." << std::endl;
		return;
	}
	std::cout << _cList[index].firstName << std::endl;
	std::cout << _cList[index].lastName << std::endl;
	std::cout << _cList[index].nickname << std::endl;
	std::cout << _cList[index].phoneNumber << std::endl;
	std::cout << _cList[index].darkestSecret << std::endl;
}