/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AType.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:36 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 13:26:04 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AType.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AType::AType()
{
}

AType::AType( const AType & src )
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
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AType const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */