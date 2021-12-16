/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:29 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 17:17:21 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Float::Float() : AType()
{
}

Float::Float(std::string const & input) : AType(input)
{
	_precision = 0;
	if (this->getStr().find("inf") != std::string::npos) {
		if (this->getStr()[0] == '+')
			this->_converted = fl::infinity();
		else
			this->_converted = -fl::infinity();
	}
	else if (this->getStr() == "nanf") {
		this->_converted = fl::quiet_NaN();
	}
	else {
		std::stringstream ss;
		ss << input;
		ss >> this->_converted;
		std::string::size_type i = -1;
		while (input[++i] != '.');
		while (input[++i] != 'f')
			_precision++;
	}
}

Float::Float(Char const & c)
{
	this->_converted = static_cast<float>(c.getConverted());
}

Float::Float(Integer const & i)
{
	this->_converted = static_cast<float>(i.getConverted());
	if (!std::isprint(this->_converted))
		throw NonDisplayException();
}

Float::Float(Double const & d)
{
	if (d.getConverted() == dl::quiet_NaN()
		|| d.getConverted() == dl::infinity() || d.getConverted() == -dl::infinity())
		throw ImpossibleConvException();
	this->_converted = static_cast<Float>(d.getConverted());
	if (!std::isprint(this->_converted))
		throw NonDisplayException();
}

Float::Float( const Float & src ) : AType(src), _converted(src._converted)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Float::~Float()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Float &				Float::operator=( Float const & rhs )
{
	if ( this != &rhs )
	{
		this->_converted = rhs.getConverted();
		this->_precision = rhs.getPrecision();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Float const & i )
{
	if (i.getConverted() == fl::infinity())
		o << "float: +inff";
	else if (i.getConverted() == -fl::infinity())
		o << "float: -inff";
	else if (i.getConverted() == fl::quiet_NaN())
		o << "float: nanf";
	else
		o << "float: " << std::setprecision(i.getPrecision()) << i.getConverted() << 'f';
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

char					Float::toChar() const {
	return static_cast<char>(this->_converted);
}

int						Float::toInt() const {
	return static_cast<int>(this->_converted);
}

float					Float::toFloat() const {
	return this->_converted;
}

double					Float::toDouble() const {
	return static_cast<double>(this->_converted);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */