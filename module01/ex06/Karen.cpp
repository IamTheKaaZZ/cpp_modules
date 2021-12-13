/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:30:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/13 13:14:50 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void)
{
	_func_lookup_table[0] = s_lookup("DEBUG", &Karen::debug, eDebug);
	_func_lookup_table[1] = s_lookup("INFO", &Karen::info, eInfo);
	_func_lookup_table[2] = s_lookup("WARNING", &Karen::warning, eWarning);
	_func_lookup_table[3] = s_lookup("ERROR", &Karen::error, eError);
	_func_lookup_table[4] = s_lookup("", NULL, eWTF);
}

Karen::~Karen(void) {

}

void	Karen::complain(std::string level) const {
	int i = -1;
	while (_func_lookup_table[++i].fp != NULL) {
		if (level == _func_lookup_table[i].key) ((this->*_func_lookup_table[i].fp)());
	}
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

Karen::level_code	Karen::_hashstr(string const& levelstr) const {
	int i = -1;
	while (_func_lookup_table[++i].fp != NULL) {
		if (levelstr == _func_lookup_table[i].key) return _func_lookup_table[i].lvl;
	}
	return eWTF;
}
