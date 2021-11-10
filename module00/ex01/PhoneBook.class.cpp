/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:58:20 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/10 11:40:53 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
	_oldest = 0;
	// cout << "PhoneBook constructor called." << endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	// cout << "PhoneBook destructor called." << endl;
	return;
}

void    PhoneBook::setContact(void) {
	string fName;
	string lName;
	string nName;
	string pNum;
	string dSec;

	cout << "First name: ";
	getline(cin, fName);
	cout << "Last name: ";
	getline(cin, lName);
	cout << "Nickname: ";
	getline(cin, nName);
	cout << "Phone Number: ";
	getline(cin, pNum);
	cout << "Darkest secret: ";
	getline(cin, dSec);
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
	cout << setw(10) << "index";
	cout << "|";
	cout << setw(10) << "first name";
	cout << "|";
	cout << setw(10) << "last name";
	cout << "|";
	cout << setw(10) << "nickname" << endl;
	size_t	i = -1;
	while (!_cList[++i].isEmpty() && i < 8)
	{
		cout << setw(10) << i;
		cout << "|";
		_checkColumn(_cList[i].firstName);
		cout << "|";
		_checkColumn(_cList[i].lastName);
		cout << "|";
		_checkColumn(_cList[i].nickname);
		cout << endl;
	}
}

void	PhoneBook::_checkColumn(string str) const {
	if (str.length() > 10)
		cout << setw(9) << str.substr(0, 9) << '.';
	else
		cout << setw(10) << str;
}

void    PhoneBook::getContact(string input) const {
	if (!_isNumber(input))
	{
		cout << "Input is not a positive number." << endl;
		return;
	}
	int index = atoi(input.c_str());
	if (_cList[index].isEmpty())
	{
		cout << "No Contact found on index." << endl;
		return;
	}
	cout << _cList[index].firstName << endl;
	cout << _cList[index].lastName << endl;
	cout << _cList[index].nickname << endl;
	cout << _cList[index].phoneNumber << endl;
	cout << _cList[index].darkestSecret << endl;
}

bool	PhoneBook::_isNumber(string input) const {
	for (string::iterator it = input.begin(); it != input.end(); ++it) {
		if (std::isdigit(*it) == 0)
			return false;
	}
	return true;
}