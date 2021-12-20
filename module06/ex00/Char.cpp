/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:55 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 13:41:35 by bcosters         ###   ########.fr       */
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
	std::cout << "Char constructor" << std::endl;
	if (!std::isprint(this->_converted))
		_display = false;
	else
		_display = true;
}

Char::Char(Integer const & i) : AType(i), _possible(true)
{
	std::cout << "Char from Int constructor" << std::endl;
	this->_converted = static_cast<char>(i.getConverted());
	if (!std::isprint(this->_converted))
		_display = false;
	else
		_display = true;
}

Char::Char(Float const & f) : AType(f)
{
	std::cout << "Char from Float constructor" << std::endl;
	if (f.getConverted() != f.getConverted()
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

Char::Char(Double const & d) : AType(d)
{
	std::cout << "Char from Double constructor" << std::endl;
	if (d.getConverted() != d.getConverted()
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
	std::cout << "Char copy constructor" << std::endl;
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
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AType*					Char::toChar() const {
	return new Char(*this);
}

AType*				Char::toInt() const {
	return new Integer(*this);
}

AType*					Char::toFloat() const {
	return new Float(*this);
}

AType*				Char::toDouble() const {
	return new Double(*this);
}

void				Char::convertPrint() const {
	AType*	I = this->toInt();
	AType*	F = this->toFloat();
	AType*	D = this->toDouble();
	std::cout << *this;
	std::cout << *static_cast<Integer*>(I);
	std::cout << *static_cast<Float*>(F);
	std::cout << *static_cast<Double*>(D);
	delete I;
	delete F;
	delete D;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */