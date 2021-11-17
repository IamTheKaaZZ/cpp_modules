/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:30:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/17 17:32:56 by bcosters         ###   ########.fr       */
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

void	Karen::filter(std::string level) const {
	switch (_hashstr(level)) {
		case eDebug:
			std::cout << "[ " << level << " ]" << std::endl;
			complain(level);
			level = "INFO";
		case eInfo:
			std::cout << "[ " << level << " ]" << std::endl;
			complain(level);
			level = "WARNING";
		case eWarning:
			std::cout << "[ " << level << " ]" << std::endl;
			complain(level);
			level = "ERROR";
		case eError:
			std::cout << "[ " << level << " ]" << std::endl;
			complain(level);
			break;
		default:
			std::cout << "[ Incomprehensible mumbling that really defines a Karen ]" << std::endl << std::endl;
	}
}

const Karen::StrToF&	Karen::getMap(void) const{
	return this->_fmap;
}

void	Karen::debug(void) const {
	std::cout << "WhY aRe YoU dEbUgGiNg ?!?!?!?!" << std::endl << std::endl;
}

void	Karen::info(void) const {
	std::cout << "WhErE's Ma InFoOoO ?!?!?!?!" << std::endl << std::endl;
}

void	Karen::warning(void) const {
	std::cout << "FiNaL wArNiNg ?!?!?!?!" << std::endl << std::endl;
}

void	Karen::error(void) const {
	std::cout << "I want to speak to your system administrator, gimme sudo access ?!?!?!?!" << std::endl << std::endl;
}

level_code	Karen::_hashstr(string const& levelstr) const {
	if (levelstr == "DEBUG") return eDebug;
	if (levelstr == "INFO") return eInfo;
	if (levelstr == "WARNING") return eWarning;
	if (levelstr == "ERROR") return eError;
	return eWTF;
}
