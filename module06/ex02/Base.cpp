/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:30:16 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 16:06:41 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Base::Base()
{
}

Base::Base( const Base & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Base::~Base()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Base &				Base::operator=( Base const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/*
** --------------------------------- EXTRA FTS --------------------------------
*/

Base*			generate() {
	int	ran = (rand() % 3);
	switch (ran)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void			identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "It's A!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's B!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's C!" << std::endl;
	else
		std::cout << "It's Not a derived class!" << std::endl;
}

void			identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "It's A!" << std::endl;
	}
	catch (std::bad_cast & e) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "It's B!" << std::endl;
		}
		catch (std::bad_cast & e) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "It's C!" << std::endl;
			}
			catch (std::bad_cast & e) {
				std::cout << "It's Not a derived class!" << std::endl;
			}
		}
	}
}

/* ************************************************************************** */