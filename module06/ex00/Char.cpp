/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:55 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/17 16:54:03 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Char.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Char::Char() : AType(), _converted(0), _possible(false), _display(false)
{
}

Char::Char(std::string const & input) :
	AType(input),
	_converted(this->getStr()[0]),
	_possible(true)
{
	if (!std::isprint(this->_converted))
		_display = false;
	else
		_display = true;
}

Char::Char(Integer const & i) : _possible(true)
{
	this->_converted = static_cast<char>(i.getConverted());
	if (!std::isprint(this->_converted))
		_display = false;
	else
		_display = true;
}

Char::Char(Float const & f)
{
	if (f.getConverted() == fl::quiet_NaN()
		|| f.getConverted() == fl::infinity() || f.getConverted() == -fl::infinity())
		_possible = false;
	else
		_possible = true;
	this->_converted = static_cast<char>(f.getConverted());
	if (!std::isprint(this->_converted))
		_display = false;
	else
		_display = true;
}

Char::Char(Double const & d)
{
	if (d.getConverted() == dl::quiet_NaN()
		|| d.getConverted() == dl::infinity() || d.getConverted() == -dl::infinity())
		_possible = false;
	else
		_possible = true;
	this->_converted = static_cast<char>(d.getConverted());
	if (!std::isprint(this->_converted))
		_display = false;
	else
		_display = true;
}

Char::Char( const Char & src ) :
	AType(src),
	_converted(src._converted),
	_possible(src._possible),
	_display(src._display)
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
		this->_possible = rhs._possible;
		this->_display = rhs._display;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Char const & i )
{
	if (!i.isPossible())
		o << "char: impossible";
	else if (!i.isDisplay())
		o << "char: Non displayable";
	else
		o << "char: '" << i.getConverted() << '\'';
	o << std::endl;
	o << i.toInt();
	o << i.toFloat();
	o << i.toDouble();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Char const &					Char::toChar() const {
	return *this;
}
Integer	const &				Char::toInt() const {
	return Integer(*this);
}

Float const &					Char::toFloat() const {
	return Float(*this);
}

Double const &				Char::toDouble() const {
	return Double(*this);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */