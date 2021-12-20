/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:29 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 12:56:47 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
# define FLOAT_HPP

# include <iostream>
# include <string>
# include "AType.hpp"
# include "Char.hpp"
# include "Integer.hpp"
// # include "Float.hpp"
# include "Double.hpp"

class Char;
class Integer;
class Double;
class Float : public AType
{

	public:

		Float(std::string const & input);
		Float(Char const & c);
		Float(Integer const & i);
		Float(Double const & d);
		Float( Float const & src );
		~Float();

		Float &		operator=( Float const & rhs );
		float			getConverted(void) const { return this->_converted; };
		int				getPrecision(void) const { return this->_precision; };
		virtual AType*		toChar(void) const;
		virtual AType*		toInt(void) const;
		virtual AType*		toFloat(void) const;
		virtual AType*		toDouble(void) const;
		virtual void		convertPrint(void) const;

	private:

		Float();
		float		_converted;
		int			_precision;
};

std::ostream &			operator<<( std::ostream & o, Float const & i );

#endif /* *********************************************************** FLOAT_H */