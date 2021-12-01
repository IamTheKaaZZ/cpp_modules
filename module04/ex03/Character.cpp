/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:17:42 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/01 17:05:58 by bcosters         ###   ########.fr       */
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

Character::Character( const Character & src ) : _name(src.getName())
{
	std::cout << "Copy Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = src._inventory[i];
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

	Character temp(rhs._name);
	if ( this != &rhs )
	{
		this->~Character();
		for (int i = 0; i < 4; i++) {
			temp._inventory[i] = rhs._inventory[i];
		}
	}
	return temp;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << "Character ";
	o << i.getName() << std::endl;
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
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &		Character::getName() const {
	return this->_name;
}

/* ************************************************************************** */