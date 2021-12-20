/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:16 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 12:55:25 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_HPP
# define INTEGER_HPP

# include <iostream>
# include <string>
# include "AType.hpp"
# include "Char.hpp"
// # include "Integer.hpp"
# include "Float.hpp"
# include "Double.hpp"

class Char;
class Float;
class Double;
class Integer : public AType
{

	public:

		Integer(std::string const & input);
		Integer(Char const & c);
		Integer(Float const & f);
		Integer(Double const & d);
		Integer( Integer const & src );
		~Integer();

		Integer &		operator=( Integer const & rhs );
		int				getConverted(void) const { return this->_converted; };
		bool			isPossible(void) const { return this->_possible; };
		virtual AType*		toChar(void) const;
		virtual AType*		toInt(void) const;
		virtual AType*		toFloat(void) const;
		virtual AType*		toDouble(void) const;
		virtual void		convertPrint(void) const;

	private:

		Integer();
		int		_converted;
		bool	_possible;

};

std::ostream &			operator<<( std::ostream & o, Integer const & i );

#endif /* ********************************************************* INTEGER_H */