/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/16 12:27:13 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

int	main(void) {
	string			str = "HI THIS IS BRAIN";
	string*			stringPTR = &str;
	string&			stringREF = str;
	stringstream	ss;
	ss << (void *)str.data();
	cout << "Memory address of original string: " << ss.str() << " - " << str << endl;
	ss.str(string());
	ss << stringPTR;
	cout << "Memory address of stringPTR: " << ss.str() << " - " << *stringPTR << endl;
	ss.str(string());
	ss << (void *)stringREF.data();
	cout << "Memory address of stringREF: " << ss.str() << " - " << stringREF << endl;
	return 0;
}