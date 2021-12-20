/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AType.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:36 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 13:49:02 by bcosters         ###   ########.fr       */
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
	std::cout << "AType constructor" << std::endl;
	size_t	found = input.find(".");
	if (_toConvert.length() == 1 && !std::isdigit(_toConvert[0])) { //Char case
		if (!std::isprint(_toConvert[0]))
			throw InvalidInputException();
	}
	else if (found == std::string::npos) { //Int case
		if (input == "-inf" || input == "+inf" || input == "nan" ||
			input == "-inff" || input == "+inff" || input == "nanf") {
				return;
		}
		std::string::size_type	i = 0;
		if (input.length() > 11)
			throw InvalidInputException();
		if (_toConvert[i] == '-')
			i++;
		while (_toConvert[i]) {
			if (!std::isdigit(_toConvert[i]))
				throw InvalidInputException();
			i++;
		}
	}
	else if (found != std::string::npos && input[found + 1]) { //float/double
		if (*input.end() == 'f') { //Float
			if (input.length() < 4 || input.length() > 16)
				throw InvalidInputException();
			for (std::string::const_iterator it = input.begin(); it != input.end(); it++) {
				if (it == input.end())
					break;
				if (it == input.begin() && *input.begin() == '-') it++;
				if (!std::isdigit(*it) && *it != '.')
					throw InvalidInputException();
			}
		}
		else { //Double
			if (input.length() < 3 || input.length() > 24)
				throw InvalidInputException();
			for (std::string::const_iterator it = input.begin(); it != input.end(); it++) {
				if (it == input.begin() && *input.begin() == '-') it++;
				if (!std::isdigit(*it) && *it != '.')
					throw InvalidInputException();
			}
		}
	}
	else
		throw InvalidInputException();
}

AType::AType( const AType & src ) : _toConvert(src._toConvert)
{
	std::cout << "AType copy constructor" << std::endl;
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