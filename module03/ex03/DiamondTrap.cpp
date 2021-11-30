/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:48:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/30 11:35:34 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
{
	this->_name = "DiamondTrap";
	ClapTrap::setName(ClapTrap::_name + _name);
	FragTrap::setHp();
	ScavTrap::setEp();
	FragTrap::setAd();
	std::cout << "Default DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	ClapTrap::setName(ClapTrap::_name + _name);
	FragTrap::setHp();
	ScavTrap::setEp();
	FragTrap::setAd();
	std::cout << "Named DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : FragTrap(src), ScavTrap(src)
{
	this->_name = src._name;
	std::cout << "Copy DiamondTrap constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_maxHP = rhs._hitpoints;
		this->_energyPoints = rhs._energyPoints;
		this->_maxEP = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_gateKeeperMode = rhs._gateKeeperMode;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	o << "<" << i.DiamondTrap::getName() << "> has " << i.getHP() << " HP, " << i.getEP() << " EP and " << i.getAD() << " Attack Damage.";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

void			DiamondTrap::whoAmI(void) const {
	std::cout << "My name is " << _name << std::endl;
	std::cout << "My clapTrap name is " << ClapTrap::getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		DiamondTrap::getName(void) const {
	return this->_name;
}

/* ************************************************************************** */