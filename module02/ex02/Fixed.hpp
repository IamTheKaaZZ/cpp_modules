/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:47:04 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/22 15:45:58 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed	//24:8 Fixed point representation
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		Fixed(int const integer);
		Fixed(float const fl);
		~Fixed();

		Fixed &		operator=( Fixed const & rhs );
		bool		operator>( Fixed const & rhs );
		bool		operator<( Fixed const & rhs );
		bool		operator>=( Fixed const & rhs );
		bool		operator<=( Fixed const & rhs );
		bool		operator==( Fixed const & rhs );
		bool		operator!=( Fixed const & rhs );
		Fixed		operator+( Fixed const & rhs );
		Fixed		operator-( Fixed const & rhs );
		Fixed		operator*( Fixed const & rhs );
		Fixed		operator/( Fixed const & rhs );
		Fixed&		operator++(void);	//prefix
		Fixed		operator++(int);	//postfix
		Fixed&		operator--(void);	//prefix
		Fixed		operator--(int);	//postfix

		int			getRawBits() const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
		static Fixed&			min(Fixed & a, Fixed & b);
		static Fixed const &	min(Fixed const & a, Fixed const & b);
		static Fixed&			max(Fixed & a, Fixed & b);
		static Fixed const &	max(Fixed const & a, Fixed const & b);

	private:

		int					_fpVal;
		static const int 	_numFracBits = 8; // always max 8 bits

};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */