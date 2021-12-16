/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:16 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 13:25:48 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_HPP
# define INTEGER_HPP

# include <iostream>
# include <string>

class Integer
{

	public:

		Integer();
		Integer( Integer const & src );
		~Integer();

		Integer &		operator=( Integer const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Integer const & i );

#endif /* ********************************************************* INTEGER_H */