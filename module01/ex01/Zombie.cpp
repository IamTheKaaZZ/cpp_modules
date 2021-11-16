/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:37:22 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/16 10:55:22 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using std::cout;
using std::endl;

Zombie::Zombie(void) : _name("nameless zombie") {
	// Zombie::announce();
}

Zombie::Zombie(std::string name) : _name(name) {
	// Zombie::announce();
}

Zombie::~Zombie(void) {
	cout << Zombie::getName() << " was destroyed!" << endl;
}

std::string	Zombie::getName(void) const {
	return this->_name;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

void	Zombie::announce(void) const {
	cout << '<' << Zombie::getName() << '>' << " BraiiiiiiinnnzzzZ..." << endl;
}