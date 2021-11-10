/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:58:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/10 11:25:56 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <iomanip>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::setw;

class	PhoneBook {

public:			//Exposed class functions/vars

	PhoneBook(void);	//Constructor
	~PhoneBook(void);	//Deconstructor

	void	setContact(void);
	void	getList(void) const;
	void	getContact(string input) const;

private:		//Helper/Internal functions/vars

	Contact	_cList[8];
	size_t	_oldest;

	void	_checkColumn(string str) const;
	bool	_isNumber(string input) const;

};

#endif