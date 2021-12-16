/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AType.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:36 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 16:57:03 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATYPE_HPP
# define ATYPE_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <stdexcept>
# include <cctype>
# include <cmath>
# include "Char.hpp"
# include "Integer.hpp"
# include "Float.hpp"
# include "Double.hpp"

typedef std::numeric_limits<char> cl;
typedef std::numeric_limits<int> il;
typedef std::numeric_limits<float> fl;
typedef std::numeric_limits<double> dl;

class AType
{

	public:

		AType();
		AType(std::string const & input);
		AType( AType const & src );
		virtual ~AType();

		class InvalidInputException : std::exception {
			char const * what() const throw() {
				return ("The input string is invalid.");
			}
		};
		class NonDisplayException : std::exception {
			char const * what() const throw() {
				return ("Non displayable");
			}
		};
		class ImpossibleConvException : std::exception {
			char const * what() const throw() {
				return ("impossible");
			}
		};
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