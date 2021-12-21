/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:22:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/21 10:46:41 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap(), _gateKeeperMode(false)
{
	ClapTrap::_name = "ScavTrap";
	ClapTrap::_hitpoints = 100;
	ClapTrap::_maxHP = 100;
	ClapTrap::_energyPoints = 50;
	ClapTrap::_maxEP = 50;
	ClapTrap::_attackDamage = 20;
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gateKeeperMode(false)
{
	ClapTrap::_hitpoints = 100;
	ClapTrap::_maxHP = 100;
	ClapTrap::_energyPoints = 50;
	ClapTrap::_maxEP = 50;
	ClapTrap::_attackDamage = 20;
	std::cout << "Named ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
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
		ClapTrap::operator=(rhs);
		this->_gateKeeperMode = rhs._gateKeeperMode;
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