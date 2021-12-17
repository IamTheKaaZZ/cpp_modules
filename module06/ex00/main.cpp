/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:53:13 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/17 17:08:40 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AType.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
		std::cerr << "Wrong number of arguments (max 1)." << std::endl;
	std::string input(argv[1]);
	AType*	type = NULL;
	size_t	found;
	try {
		if (input.length() == 1 && !std::isdigit(input[0]))
			type = new Char(input);
		else if ((found = input.find(".") != std::string::npos)) {
			if ((found = input.find("f") != std::string::npos)) { //float
				type = new Float(input);
			}
			else { //double
				type = new Double(input);
			}
		}
		else { //int
			type = new Integer(input);
		}
	}
	catch (AType::InvalidInputException & e) {
		std::cout << e.what() << std::endl;
		if (type)
			delete type;
		return 1;
	}
	if (type) {
		std::cout << *type;
		delete type;
	}
	return 0;
}