/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crapsoft.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:54:53 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/08 16:57:10 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv) {

	std::string	input;

	while (argc) {
		std::cout << "CrAPSoft >";
		getline(std::cin, input);
		if (input.compare("ADD") != 0 && input.compare("SEARCH") != 0
			&& input.compare("EXIT") != 0)
			continue ;
		if (!input.compare("ADD")) {

		}
		else if (!input.compare("SEARCH")) {

		}
		else if (!input.compare("EXIT")) {
			break ;
		}
	}
	return 0;
}