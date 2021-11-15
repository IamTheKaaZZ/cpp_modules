/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:09:21 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/15 12:36:38 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) {
	// cout << "Empty Contact constructor called." << endl;
	return;
}

Contact::Contact(string a, string b, string c, string d, string e) :
	_firstName(a),
	_lastName(b),
	_nickname(c),
	_phoneNumber(d),
	_darkestSecret(e)
{
	// cout << "Contact constructor called." << endl;
	return;
}

Contact::~Contact(void)
{
	// cout << "Contact destructor called." << endl;
	return;
}

bool	Contact::isEmpty(void) const {
	if (this->_firstName.length() == 0
		&& this->_lastName.length() == 0
		&& this->_nickname.length() == 0
		&& this->_phoneNumber.length() == 0
		&& this->_darkestSecret.length() == 0)
		return true;
	else
		return false;
}

string	Contact::getFirstname(void) const {
	return this->_firstName;
}

string	Contact::getLastname(void) const {
	return this->_lastName;
}

string	Contact::getNickname(void) const {
	return this->_nickname;
}

string	Contact::getPhonenumber(void) const {
	return this->_phoneNumber;
}

string	Contact::getDarkestsecret(void) const {
	return this->_darkestSecret;
}
