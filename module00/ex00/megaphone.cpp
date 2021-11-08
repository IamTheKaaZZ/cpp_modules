/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:42:48 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/08 16:45:47 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[]) {

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++) {
				if (argv[i][j] > 96 && argv[i][j] < 123)	//Check if char is lowercase ascii
					std::cout << (char)(argv[i][j] - 32);	//Print as uppercase ascii
				else
					std::cout << (char)(argv[i][j]);		//Char is not lowercase/alpha => print it
			}
		}
		std::cout << std::endl;								//Print newline
	}
	return 0;
}
