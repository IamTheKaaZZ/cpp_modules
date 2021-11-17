/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:40:02 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/17 12:30:23 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

using std::cout;
using std::endl;

Weapon def = Weapon("Nothing");

HumanA::HumanA(void) : _name("Nobody"), _w(def) {
	return;
}

HumanA::HumanA(string name, Weapon& w) : _name(name), _w(w) {
	return;
}

HumanA::~HumanA(void) {
	return;
}

void	HumanA::attack(void) const {
	cout << this->_name << " attacks with his " << this->_w.getType() << endl;
}