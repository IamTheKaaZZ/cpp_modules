/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:58:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/09 16:54:35 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <iomanip>

class	PhoneBook {

public:

	PhoneBook(void);	//Constructor
	~PhoneBook(void);	//Deconstructor

	void	setContact(void);
	void	getList(void) const;
	void	getContact(int index) const;

private:

	Contact	_cList[8];
	size_t	_oldest;

};

#endif