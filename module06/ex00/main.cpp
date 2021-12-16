/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:53:13 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 13:38:12 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath>



int	main(int argc, char **argv) {
	if (argc != 2)
		std::cerr << "Wrong number of arguments (max 1)." << std::endl;
	double				buffer = 0.0;
	std::istringstream input(argv[1]);
	char				c = static_cast<char>(buffer);
	int					i = static_cast<int>(buffer);
	float				f = static_cast<float>(buffer);
	std::cout << "char: '" << c << '\'' << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout.setf(std::ios_base::fmtflags(), std::ios_base::floatfield);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << buffer << std::endl;
}