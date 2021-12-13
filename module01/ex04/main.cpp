/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/13 09:58:22 by bcosters         ###   ########.fr       */
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
	ofstream	ofs(string(argv[1]).append(".replace"));
	if (!ofs.is_open()) {
		cerr << "Error opening output file." << endl;
	}
	string		needle = argv[2];
	string		replacement = argv[3];
	size_t		found;
	for (string line; getline(ifs, line);) {			//For each line in the file
		found = line.find(needle);						//find the starting position of the needle
		while (found != string::npos) {					//While you can find the needle string
			if (found != string::npos) {				//IF the needle is found
				line.erase(found, needle.length());		//erase the needle from found with its entire length
				line.insert(found, replacement);		//insert the replacement at position found
				found = line.find(needle, found + replacement.size());					//find the starting position of the next needle
			}
			else
				break;
		}
		ofs << line << endl;							//Add the line to the outputfile
	}
	ifs.close();
	ofs.close();
	return 0;
}