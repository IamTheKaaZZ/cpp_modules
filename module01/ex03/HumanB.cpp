/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:47:13 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/17 11:08:26 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

using std::cout;
using std::endl;

HumanB::HumanB(void) : _w(NULL) {
	return;
}

HumanB::HumanB(string name) : _name(name), _w(NULL) {
	return;
}

HumanB::~HumanB(void) {
	return;
}

void	HumanB::setWeapon(Weapon& w) {
	this->_w = &w;
}

void	HumanB::attack(void) const {
	cout << this->_name << " attacks with his ";
	if (_w == NULL)
		cout << "his bare fucking fists because he has no weapon!" << endl;
	else
		cout << this->_w->getType() << endl;
}