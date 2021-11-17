/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:30:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/17 16:54:13 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void) {	//Assign a member function to each string
	_fmap[string("DEBUG")] = &Karen::debug;
	_fmap[string("INFO")] = &Karen::info;
	_fmap[string("WARNING")] = &Karen::warning;
	_fmap[string("ERROR")] = &Karen::error;
}

Karen::~Karen(void) {

}

void	Karen::complain(std::string level) const {
	Karen::StrToF::const_iterator	it = getMap().find(level);	//Iterate over the keys to find level
	if (it == getMap().end())									//if key is not found, stop
		return;
	(this->*(it->second))();									//If key is found, run the second data aka the mapped function to it
}

const Karen::StrToF&	Karen::getMap(void) const{
	return this->_fmap;
}

void	Karen::debug(void) const {
	std::cout << "WhY aRe YoU dEbUgGiNg ?!?!?!?!" << std::endl;
}

void	Karen::info(void) const {
	std::cout << "WhErE's Ma InFoOoO ?!?!?!?!" << std::endl;
}

void	Karen::warning(void) const {
	std::cout << "FiNaL wArNiNg ?!?!?!?!" << std::endl;
}

void	Karen::error(void) const {
	std::cout << "I want to speak to your system administrator, gimme sudo access ?!?!?!?!" << std::endl;
}