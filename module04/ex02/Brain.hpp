/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:56:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/30 14:25:57 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:

		std::string	ideas[100];
		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );

	private:

		void	genRandoIdeas(void);

};

std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* *********************************************************** BRAIN_H */