/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:17:55 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 13:25:44 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_HPP
# define CHAR_HPP

# include <iostream>
# include <string>

class Char
{

	public:

		Char();
		Char( Char const & src );
		~Char();

		Char &		operator=( Char const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Char const & i );

#endif /* ************************************************************ CHAR_H */