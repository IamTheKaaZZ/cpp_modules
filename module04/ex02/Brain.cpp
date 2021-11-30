/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:56:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/30 14:34:25 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Default Brain constructor called." << std::endl;
	genRandoIdeas();
}

Brain::Brain( const Brain & src )
{
	std::cout << "Copy Brain constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
	}
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & i )
{
	for (int j = 0; j < 100; j++) {
		o << " Idea " << j << " " << i.ideas[j] << std::endl;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

#include <ctime>
#include <iostream>
#include <unistd.h>

void		Brain::genRandoIdeas(void) {
	int const len = 12;
	static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    srand((unsigned)time(NULL) * getpid());     
    std::string tmp_s;
    tmp_s.reserve(len);

	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < len; ++i) {
			tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
		}
		this->ideas[j] = tmp_s;
		tmp_s.clear();
		tmp_s.reserve(len);
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */