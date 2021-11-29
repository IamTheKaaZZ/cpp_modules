/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:22:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/29 14:24:06 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : _gateKeeperMode(false)
{
	this->setName("ScavTrap");
	this->setHP(100);
	this->setEP(50);
	this->setAD(20);
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _gateKeeperMode(false)
{
	this->setName(name);
	this->setHP(100);
	this->setEP(50);
	this->setAD(20);
	std::cout << "Named ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	this->setName(src.getName());
	this->setHP(src.getHP());
	this->setEP(src.getEP());
	this->setAD(src.getAD());
	this->_gateKeeperMode = src._gateKeeperMode;
	std::cout << "Copy ScavTrap constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->setName(rhs.getName());
		this->setHP(rhs.getHP());
		this->setEP(rhs.getEP());
		this->setAD(rhs.getAD());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
{
	o << "ScavTrap <" << i.getName() << "> has " << i.getHP() << " HP, " << i.getEP() << " EP and " << i.getAD() << " Attack Damage.";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			ScavTrap::guardGate(void) {
	if (this->_gateKeeperMode) {
		this->_gateKeeperMode = false;
		std::cout << "ScavTrap <" << this->getName() << "> is no longer shouting \"HODOR HODOR!\"" << std::endl;
	}
	else {
		this->_gateKeeperMode = true;
		std::cout << "ScavTrap <" << this->getName() << "> started shouting \"HODOR HODOR!\"" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */