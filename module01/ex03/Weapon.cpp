/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:29:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/17 10:36:09 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
	return;
}

Weapon::Weapon(string type) : _type(type) {
	return;
}

Weapon::~Weapon(void) {
	return;
}

string const &	Weapon::getType(void) const {
	string const &	type = this->_type;
	return type;
}

void	Weapon::setType(string name) {
	this->_type = name;
}