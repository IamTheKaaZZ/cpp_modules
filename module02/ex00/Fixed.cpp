/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:46:45 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/22 13:15:43 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _fpVal(0 * (1 << _numFracBits))
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed( const Fixed & src ) : _fpVal(src._fpVal)
{
	std::cout << "Copy constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignment operater called." << std::endl;
	if ( this != &rhs )
	{
		this->_fpVal = rhs.getRawBits();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	std::cout << "Output overload called." << std::endl;
	o << i.getRawBits();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int		Fixed::getRawBits() const {
	std::cout << "getRawBits called." << std::endl;
	return this->_fpVal;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits called." << std::endl;
	this->_fpVal = raw;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */