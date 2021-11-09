/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:58:40 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/08 17:08:35 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"

class	PhoneBook {

private:

	Contact	_cList[8];

public:

	PhoneBook(void);	//Constructor
	~PhoneBook(void);	//Deconstructor

	void	setContact(void);
	void	getList(void) const;
	void	getContact(int index) const;

};