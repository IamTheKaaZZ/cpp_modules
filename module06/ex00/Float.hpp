/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:29 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 17:14:33 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
# define FLOAT_HPP

# include <iostream>
# include <string>
# include "AType.hpp"

class Float : public AType
{

	public:

		Float(std::string const & input);
		Float(Char const & c);
		Float(Integer const & f);
		Float(Double const & d);
		Float( Float const & src );
		~Float();

		Float &		operator=( Float const & rhs );
		float			getConverted(void) const { return this->_converted; };
		int				getPrecision(void) const { return this->_precision; };
		char			toChar(void) const;
		int				toInt(void) const;
		float			toFloat(void) const;
		double			toDouble(void) const;

	private:

		Float();
		float		_converted;
		int			_precision;
};

std::ostream &			operator<<( std::ostream & o, Float const & i );

#endif /* *********************************************************** FLOAT_H */