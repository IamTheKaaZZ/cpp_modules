/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:17:42 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/07 17:30:00 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : _name("Nobody")
{
	std::cout << "Default Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Parameter Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character( const Character & src ) : _name(src._name)
{
	std::cout << "Copy Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		this->_name = rhs.getName();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << "Character ";
	o << i.getName() << std::endl;
	o << "Has the following inventory:" << std::endl;
	for (int j = 0; j < 4; j++) {
		o << "Slot " << j << " ";
		if (i.getInvItem(j) != NULL)
			o << ": " << *i.getInvItem(j);
		else
			o << ": Empty.";
		o << std::endl;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void					Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			break;
		}
	}
}

void					Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return;
	if (this->_inventory[idx])
		this->_inventory[idx] = NULL;
}

void					Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return;
	if (this->_inventory[idx]) {
		std::cout << this->getName() << " ";
		this->_inventory[idx]->use(target);
		this->unequip(idx);
	}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &		Character::getName() const {
	return this->_name;
}

AMateria*				Character::getInvItem(int idx) const {
	return this->_inventory[idx];
}

/* ************************************************************************** */