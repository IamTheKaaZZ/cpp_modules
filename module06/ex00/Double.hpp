/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/16 13:24:43 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
# define DOUBLE_HPP

# include <iostream>
# include <string>

class Double
{

	public:

		Double();
		Double( Double const & src );
		~Double();

		Double &		operator=( Double const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Double const & i );

#endif /* ********************************************************** DOUBLE_H */