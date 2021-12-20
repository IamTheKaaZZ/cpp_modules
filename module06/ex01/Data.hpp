/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:03:09 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 15:09:13 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{

	public:

		Data();
		Data(std::string const & string, int const & num);
		Data( Data const & src );
		~Data();

		Data &		operator=( Data const & rhs );
		std::string const &	getStr() const { return this->_string; };
		int const &			getNbr() const { return this->_number; };

	private:

		std::string	_string;
		int			_number;

};

std::ostream &			operator<<( std::ostream & o, Data const & i );

#endif /* ************************************************************ DATA_H */