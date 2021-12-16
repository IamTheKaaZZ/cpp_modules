/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:55 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 16:57:44 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_HPP
# define CHAR_HPP

# include <iostream>
# include <string>
# include "AType.hpp"

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
		char		toChar(void) const;
		int			toInt(void) const;
		float		toFloat(void) const;
		double		toDouble(void) const;

	private:

		Char();
		char	_converted;

};

std::ostream &			operator<<( std::ostream & o, Char const & i );

#endif /* ************************************************************ CHAR_H */