/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:47:04 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/22 13:47:02 by bcosters         ###   ########.fr       */
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

		int			getRawBits() const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

	private:

		int					_fpVal;
		static const int 	_numFracBits = 8; // always max 8 bits

};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */