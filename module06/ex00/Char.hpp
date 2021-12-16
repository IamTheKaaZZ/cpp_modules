/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:55 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 13:49:46 by bcosters         ###   ########.fr       */
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
		Char( Char const & src );
		~Char();

		Char &		operator=( Char const & rhs );
		char			getConverted(void) const { return this->_converted; };
		virtual char	toChar(void) const;
		virtual int		toInt(void) const;
		virtual float	toFloat(void) const;
		virtual double	toDouble(void) const;

	private:

		Char();
		char	_converted;

};

std::ostream &			operator<<( std::ostream & o, Char const & i );

#endif /* ************************************************************ CHAR_H */