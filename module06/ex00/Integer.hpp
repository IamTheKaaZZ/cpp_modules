/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:16 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/17 17:11:32 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_HPP
# define INTEGER_HPP

# include <iostream>
# include <string>
# include "AType.hpp"

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
		Char const &		toChar(void) const;
		Integer	const &		toInt(void) const;
		Float const &		toFloat(void) const;
		Double const &		toDouble(void) const;

	private:

		Integer();
		int		_converted;
		bool	_possible;

};

std::ostream &			operator<<( std::ostream & o, Integer const & i );

#endif /* ********************************************************* INTEGER_H */