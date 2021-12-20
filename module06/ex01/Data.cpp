/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:03:09 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 15:12:16 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Data::Data() : _string(""), _number(0)
{
}

Data::Data(std::string const & string, int const & num) : _string(string), _number(num)
{
}

Data::Data( const Data & src ) : _string(src._string), _number(src._number)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Data::~Data()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Data &				Data::operator=( Data const & rhs )
{
	if ( this != &rhs )
	{
		this->_string = rhs.getStr();
		this->_number = rhs.getNbr();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Data const & i )
{
	o << "String = " << i.getStr() << std::endl;
	o << "Number = " << i.getNbr();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */