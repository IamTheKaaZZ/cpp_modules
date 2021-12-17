/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:15 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/17 16:56:15 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Integer::Integer() : AType(), _converted(0), _possible(false)
{
}

Integer::Integer(std::string const & input) : AType(input), _possible(true)
{
	std::stringstream ss;
	ss << input;
	ss >> this->_converted;
}

Integer::Integer(Char const & c) : _possible(true)
{
	this->_converted = static_cast<int>(c.getConverted());
}

Integer::Integer(Float const & f)
{
	if (f.getConverted() == fl::quiet_NaN()
		|| f.getConverted() == fl::infinity() || f.getConverted() == -fl::infinity())
		_possible = false;
	else
		_possible = true;
	this->_converted = static_cast<int>(f.getConverted());
}

Integer::Integer(Double const & d)
{
	if (d.getConverted() == dl::quiet_NaN()
		|| d.getConverted() == dl::infinity() || d.getConverted() == -dl::infinity())
		_possible = false;
	else
		_possible = true;
	this->_converted = static_cast<char>(d.getConverted());
}

Integer::Integer( const Integer & src ) : AType(src),
	_converted(src._converted),
	_possible(src._possible)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Integer::~Integer()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Integer &				Integer::operator=( Integer const & rhs )
{
	if ( this != &rhs )
	{
		this->_converted = rhs.getConverted();
		this->_possible = rhs._possible;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Integer const & i )
{
	o << i.toChar();
	if (!i.isPossible())
		o << "int: impossible";
	else
		o << "int: " << i.getConverted();
	o << std::endl;
	o << i.toFloat();
	o << i.toDouble();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Char const &					Integer::toChar() const {
	return Char(*this);
}

Integer const &				Integer::toInt() const {
	return *this;
}

Float const &					Integer::toFloat() const {
	return Float(*this);
}

Double const &					Integer::toDouble() const {
	return Double(*this);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */