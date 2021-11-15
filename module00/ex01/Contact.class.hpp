/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:58:21 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/15 12:33:55 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>
# include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

class	Contact {

public:

	Contact(void);
	Contact(string a, string b, string c, string d, string e);
	~Contact(void);
	bool	isEmpty(void) const;
	string	getFirstname(void) const;
	string	getLastname(void) const;
	string	getNickname(void) const;
	string	getPhonenumber(void) const;
	string	getDarkestsecret(void) const;

private:

	string		_firstName;
	string		_lastName;
	string		_nickname;
	string		_phoneNumber;
	string		_darkestSecret;
};

#endif