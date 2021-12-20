/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:29 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 13:44:03 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Float::Float() : AType(), _converted(0), _precision(1)
{
}

Float::Float(std::string const & input) : AType(input)
{
	std::cout << "Float constructor" << std::endl;
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

Float::Float(Char const & c) : AType(c), _precision(1)
{
	std::cout << "Float from Char constructor" << std::endl;
	this->_converted = static_cast<float>(c.getConverted());
}

Float::Float(Integer const & i) : AType(i), _precision(1)
{
	std::cout << "Float from Int constructor" << std::endl;
	this->_converted = static_cast<float>(i.getConverted());
}

Float::Float(Double const & d) : AType(d), _precision(d.getPrecision())
{
	std::cout << "Float from Double constructor" << std::endl;
	if (d.getConverted() == dl::quiet_NaN()) {
		this->_converted = fl::quiet_NaN();
	}
	else if (d.getConverted() == dl::infinity()) {
		this->_converted = fl::infinity();
	}
	else if (d.getConverted() == -dl::infinity()) {
		this->_converted = -fl::infinity();
	}
	else
		this->_converted = static_cast<float>(d.getConverted());
}

Float::Float( const Float & src ) : AType(src),
	_converted(src._converted),
	_precision(src._precision)
{
	std::cout << "Float copy constructor" << std::endl;
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
		o << "float: " << std::fixed << std::setprecision(i.getPrecision()) << i.getConverted() << 'f';
	o << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AType*						Float::toChar() const {
	return new Char(*this);
}

AType*					Float::toInt() const {
	return new Integer(*this);
}

AType*					Float::toFloat() const {
	return new Float(*this);
}

AType*					Float::toDouble() const {
	return new Double(*this);
}

void				Float::convertPrint() const {
	AType*	C = this->toChar();
	AType*	I = this->toInt();
	AType*	D = this->toDouble();
	std::cout << *static_cast<Char*>(C);
	std::cout << *static_cast<Integer*>(I);
	std::cout << *this;
	std::cout << *static_cast<Double*>(D);
	delete C;
	delete I;
	delete D;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */