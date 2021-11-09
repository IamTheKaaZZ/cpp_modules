/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:09:21 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/09 17:03:50 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) {
	std::cout << "Empty Contact constructor called." << std::endl;
	return;
}

Contact::Contact(std::string a, std::string b, std::string c, std::string d, std::string e) :
	firstName(a),
	lastName(b),
	nickname(c),
	phoneNumber(d),
	darkestSecret(e)
{
	std::cout << "Contact constructor called." << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called." << std::endl;
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