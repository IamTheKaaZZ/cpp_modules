/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:15 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 17:10:25 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Integer::Integer() : AType()
{
}

Integer::Integer(std::string const & input) : AType(input)
{
	std::stringstream ss;
	ss << input;
	ss >> this->_converted;
}

Integer::Integer(Char const & c)
{
	this->_converted = static_cast<int>(c.getConverted());
}

Integer::Integer(Float const & f)
{
	if (f.getConverted() == fl::quiet_NaN()
		|| f.getConverted() == fl::infinity() || f.getConverted() == -fl::infinity())
		throw ImpossibleConvException();
	this->_converted = static_cast<int>(f.getConverted());
}

Integer::Integer(Double const & d)
{
	if (d.getConverted() == dl::quiet_NaN()
		|| d.getConverted() == dl::infinity() || d.getConverted() == -dl::infinity())
		throw ImpossibleConvException();
	this->_converted = static_cast<char>(d.getConverted());
}

Integer::Integer( const Integer & src ) : AType(src), _converted(src._converted)
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
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Integer const & i )
{
	o << "int: " << i.getConverted();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

char					Integer::toChar() const {
	char ret = static_cast<char>(this->_converted);
	if (!std::isprint(ret))
		throw NonDisplayException();
	else
		return ret;
}

int						Integer::toInt() const {
	return this->_converted;
}

float					Integer::toFloat() const {
	return static_cast<float>(this->_converted);
}

double					Integer::toDouble() const {
	return static_cast<double>(this->_converted);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */