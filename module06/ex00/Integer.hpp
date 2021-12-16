/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:16 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 17:00:02 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_HPP
# define INTEGER_HPP

# include <iostream>
# include <string>
# include "AType.hpp"

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
		char			toChar(void) const;
		int				toInt(void) const;
		float			toFloat(void) const;
		double			toDouble(void) const;

	private:

		Integer();
		int		_converted;

};

std::ostream &			operator<<( std::ostream & o, Integer const & i );

#endif /* ********************************************************* INTEGER_H */