/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 12:57:07 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
# define DOUBLE_HPP

# include <iostream>
# include <string>
# include "AType.hpp"
# include "Char.hpp"
# include "Integer.hpp"
# include "Float.hpp"
// # include "Double.hpp"

class Char;
class Integer;
class Float;
class Double : public AType
{

	public:

		Double(std::string const & input);
		Double(Char const & c);
		Double(Integer const & i);
		Double(Float const & f);
		Double( Double const & src );
		~Double();

		Double &		operator=( Double const & rhs );
		double			getConverted(void) const { return this->_converted; };
		int				getPrecision(void) const { return this->_precision; };
		virtual AType*		toChar(void) const;
		virtual AType*		toInt(void) const;
		virtual AType*		toFloat(void) const;
		virtual AType*		toDouble(void) const;
		virtual void		convertPrint(void) const;

	private:

		Double();
		double		_converted;
		int			_precision;
};

std::ostream &			operator<<( std::ostream & o, Double const & i );

#endif /* ********************************************************** DOUBLE_H */