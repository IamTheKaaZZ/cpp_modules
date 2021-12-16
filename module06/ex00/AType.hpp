/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AType.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:36 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 13:25:28 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATYPE_HPP
# define ATYPE_HPP

# include <iostream>
# include <string>

class AType
{

	public:

		AType();
		AType( AType const & src );
		virtual ~AType();

		AType &			operator=( AType const & rhs );
		std::string		getStr(void) const { return this->_toConvert; };
		void			setStr(std::string const & str) { this->_toConvert = str; };
		virtual char	toChar(void) const = 0;
		virtual int		toInt(void) const = 0;
		virtual float	toFloat(void) const = 0;
		virtual double	toDouble(void) const = 0;

	private:

		std::string	_toConvert;

};

std::ostream &			operator<<( std::ostream & o, AType const & i );

#endif /* *********************************************************** ATYPE_H */