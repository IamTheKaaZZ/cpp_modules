/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:55 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/17 17:11:14 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_HPP
# define CHAR_HPP

# include <iostream>
# include <string>
# include "AType.hpp"

class Integer;
class Float;
class Double;
class Char : public AType
{

	public:

		Char(std::string const & input);
		Char(Integer const & i);
		Char(Float const & f);
		Char(Double const & d);
		Char( Char const & src );
		~Char();

		Char &		operator=( Char const & rhs );
		char		getConverted(void) const { return this->_converted; };
		bool		isPossible(void) const { return this->_possible; };
		bool		isDisplay(void) const { return this->_display; };
		Char const &	toChar(void) const;
		Integer	const &	toInt(void) const;
		Float const &	toFloat(void) const;
		Double const &	toDouble(void) const;

	private:

		Char();
		char	_converted;
		bool	_possible;
		bool	_display;

};

std::ostream &			operator<<( std::ostream & o, Char const & i );

#endif /* ************************************************************ CHAR_H */