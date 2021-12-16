/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AType.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:36 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 14:13:05 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AType.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AType::AType() : _toConvert(NULL)
{
}

AType::AType(std::string const & input) : _toConvert(input)
{
	size_t	found = input.find(".");
	if (_toConvert.length() == 1) { //Char case
		if (!std::isprint(_toConvert[0]))
			throw InvalidInputException();
	}
	else if (found == std::string::npos) { //Int case
		std::string::size_type	i = 0;
		if (_toConvert[i] == '-')
			i++;
		while (_toConvert[i]) {
			if (!std::isdigit(_toConvert[i]))
				throw InvalidInputException();
			i++;
		}
	}
	else if (found != std::string::npos) { //float/double
		if (*input.end() == 'f') { //Float
			
		}
	}
}

AType::AType( const AType & src ) : _toConvert(src._toConvert)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AType::~AType()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AType &				AType::operator=( AType const & rhs )
{
	if ( this != &rhs )
	{
		this->_toConvert = rhs.getStr();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AType const & i )
{
	o << "Input = " << i.getStr();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */