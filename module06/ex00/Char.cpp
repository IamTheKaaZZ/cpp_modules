/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:55 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 17:09:11 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Char.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Char::Char() : AType(), _converted(-1)
{
}

Char::Char(std::string const & input) :
	AType(input),
	_converted(this->getStr()[0])
{
}

Char::Char(Integer const & i)
{
	this->_converted = static_cast<char>(i.getConverted());
	if (!std::isprint(this->_converted))
		throw NonDisplayException();
}

Char::Char(Float const & f)
{
	if (f.getConverted() == fl::quiet_NaN()
		|| f.getConverted() == fl::infinity() || f.getConverted() == -fl::infinity())
		throw ImpossibleConvException();
	this->_converted = static_cast<char>(f.getConverted());
	if (!std::isprint(this->_converted))
		throw NonDisplayException();
}

Char::Char(Double const & d)
{
	if (d.getConverted() == dl::quiet_NaN()
		|| d.getConverted() == dl::infinity() || d.getConverted() == -dl::infinity())
		throw ImpossibleConvException();
	this->_converted = static_cast<char>(d.getConverted());
	if (!std::isprint(this->_converted))
		throw NonDisplayException();
}

Char::Char( const Char & src ) :
	AType(src),
	_converted(src._converted)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Char::~Char()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Char &				Char::operator=( Char const & rhs )
{
	if ( this != &rhs )
	{
		this->_converted = rhs._converted;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Char const & i )
{
	o << "char: " << i.getConverted();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

char					Char::toChar() const {
	return this->_converted;
}

int						Char::toInt() const {
	return Integer(*this).getConverted();
}

float					Char::toFloat() const {
	return Float(*this).getConverted();
}

double					Char::toDouble() const {
	return Double(*this).getConverted();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */