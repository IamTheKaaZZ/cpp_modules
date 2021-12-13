/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:30:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/13 11:49:00 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void)
{
	_func_lookup_table[0] = s_lookup("DEBUG", &Karen::debug);
	_func_lookup_table[1] = s_lookup("INFO", &Karen::info);
	_func_lookup_table[2] = s_lookup("WARNING", &Karen::warning);
	_func_lookup_table[3] = s_lookup("ERROR", &Karen::error);
	_func_lookup_table[4] = s_lookup("", NULL);
}

Karen::~Karen(void) {

}

void	Karen::complain(std::string level) const {
	int i = -1;
	while (_func_lookup_table[++i].fp != NULL) {
		if (level == _func_lookup_table[i].key) ((this->*_func_lookup_table[i].fp)());
	}
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