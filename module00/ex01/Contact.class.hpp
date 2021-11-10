/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:58:21 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/10 11:09:39 by bcosters         ###   ########.fr       */
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

	string		firstName;
	string		lastName;
	string		nickname;
	string		phoneNumber;
	string		darkestSecret;

	Contact(void);
	Contact(string a, string b, string c, string d, string e);
	~Contact(void);
	bool	isEmpty(void) const;

};

#endif