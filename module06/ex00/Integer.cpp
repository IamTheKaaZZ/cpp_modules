/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:15 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 13:42:34 by bcosters         ###   ########.fr       */
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

Integer::Integer(Char const & c) : AType(c), _possible(true)
{
	std::cout << "Int from Char constructor" << std::endl;
	this->_converted = static_cast<int>(c.getConverted());
}

Integer::Integer(Float const & f) : AType(f)
{
	std::cout << "Int from Float constructor" << std::endl;
	if (f.getConverted() != f.getConverted()
		|| f.getConverted() == fl::infinity() || f.getConverted() == -fl::infinity())
		_possible = false;
	else
		_possible = true;
	this->_converted = static_cast<int>(f.getConverted());
}

Integer::Integer(Double const & d) : AType(d)
{
	std::cout << "Int from Double constructor" << std::endl;
	if (d.getConverted() != d.getConverted()
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
	std::cout << "Int copy constructor" << std::endl;
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
	if (!i.isPossible())
		o << "int: impossible";
	else
		o << "int: " << i.getConverted();
	o << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AType*					Integer::toChar() const {
	return new Char(*this);
}

AType*				Integer::toInt() const {
	return new Integer(*this);
}

AType*					Integer::toFloat() const {
	return new Float(*this);
}

AType*					Integer::toDouble() const {
	return new Double(*this);
}

void				Integer::convertPrint() const {
	AType*	C = this->toChar();
	AType*	F = this->toFloat();
	AType*	D = this->toDouble();
	std::cout << *static_cast<Char*>(C);
	std::cout << *this;
	std::cout << *static_cast<Float*>(F);
	std::cout << *static_cast<Double*>(D);
	delete C;
	delete F;
	delete D;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */