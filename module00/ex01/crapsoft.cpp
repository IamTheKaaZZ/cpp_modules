/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crapsoft.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:54:53 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/10 11:26:57 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int	main(void) {

	std::string	input;
	PhoneBook	pb;

	while (true) {
		std::cout << "CrAPSoft > ";
		getline(std::cin, input);
		if (input.compare("ADD") != 0 && input.compare("SEARCH") != 0
			&& input.compare("EXIT") != 0)
			continue ;
		if (!input.compare("ADD")) {
			pb.setContact();
		}
		else if (!input.compare("SEARCH")) {
			pb.getList();
			std::cout << "Index? > ";
			getline(std::cin, input);
			pb.getContact(input);
		}
		else if (!input.compare("EXIT")) {
			break ;
		}
	}
	return 0;
}