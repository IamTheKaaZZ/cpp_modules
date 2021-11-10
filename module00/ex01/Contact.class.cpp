/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:09:21 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/10 11:25:51 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) {
	// cout << "Empty Contact constructor called." << endl;
	return;
}

Contact::Contact(string a, string b, string c, string d, string e) :
	firstName(a),
	lastName(b),
	nickname(c),
	phoneNumber(d),
	darkestSecret(e)
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
	if (this->firstName.length() == 0
		&& this->lastName.length() == 0
		&& this->nickname.length() == 0
		&& this->phoneNumber.length() == 0
		&& this->darkestSecret.length() == 0)
		return true;
	else
		return false;
}