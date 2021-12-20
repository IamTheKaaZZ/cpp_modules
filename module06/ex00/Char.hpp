/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:55 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 12:56:41 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_HPP
# define CHAR_HPP

# include <iostream>
# include <string>
# include "AType.hpp"
// # include "Char.hpp"
# include "Integer.hpp"
# include "Float.hpp"
# include "Double.hpp"

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
		virtual AType*		toChar(void) const;
		virtual AType*		toInt(void) const;
		virtual AType*		toFloat(void) const;
		virtual AType*		toDouble(void) const;
		virtual void		convertPrint(void) const;

	private:

		Char();
		char	_converted;
		bool	_possible;
		bool	_display;

};

std::ostream &			operator<<( std::ostream & o, Char const & i );

#endif /* ************************************************************ CHAR_H */