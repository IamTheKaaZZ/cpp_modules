/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:29 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 13:24:48 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
# define FLOAT_HPP

# include <iostream>
# include <string>

class Float
{

	public:

		Float();
		Float( Float const & src );
		~Float();

		Float &		operator=( Float const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Float const & i );

#endif /* *********************************************************** FLOAT_H */