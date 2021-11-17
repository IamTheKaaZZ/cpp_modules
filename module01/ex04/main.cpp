/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/17 13:14:48 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;
using std::istringstream;
using std::ifstream;
using std::ofstream;

int	main(int argc, char **argv) {
	if (argc != 4) {
		cerr << "Wrong number of arguments." << endl;
		return 1;
	}
	if (argv[2][0] == 0 || argv[3][0] == 0) {
		cerr << "One of the strings is empty." << endl;
		return 1;
	}
	ifstream	ifs(argv[1]);
	if (!ifs.is_open()) {
		cerr << "Error opening file." << endl;
		return 1;
	}
	string		needle = argv[2];
	string		replacement = argv[3];
	for (string line; getline(ifs, line);) {	//For each line in the file

	}
	ifs.close();
	return 0;
}