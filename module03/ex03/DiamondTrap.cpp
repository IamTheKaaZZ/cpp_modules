/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:48:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/29 17:27:40 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = "DiamondTrap";
	this->ClapTrap::_name = ClapTrap::getName() + _name;
	this->ClapTrap::_hitpoints = this->FragTrap::_hitpoints;
	this->ClapTrap::_energyPoints = this->ScavTrap::_energyPoints;
	this->ClapTrap::_attackDamage = this->FragTrap::_attackDamage;
	std::cout << "Default DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	// ClapTrap::setName(ClapTrap::getName() + _name);
	// this->setHP(FragTrap::getHP());
	// this->setEP(ScavTrap::getEP());
	// this->setAD(FragTrap::getAD());
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
		// this->setName(rhs.getName());
		// this->setHP(rhs.getHP());
		// this->setEP(rhs.getEP());
		// this->setAD(rhs.getAD());
		// this->setGuard(rhs.getGuard());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	o << "<" << i.getName() << "> has " << i.getHP() << " HP, " << i.getEP() << " EP and " << i.getAD() << " Attack Damage.";
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
	std::cout << "My clapTrap name is" << getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */