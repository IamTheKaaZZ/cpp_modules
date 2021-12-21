/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:26:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/21 11:35:23 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap( FragTrap const & src );
		virtual ~FragTrap();

		FragTrap &		operator=( FragTrap const & rhs );
		void			setName(std::string name);
		void			setHp(void);
		void			setEp(void);
		void			setAd(void);
		void		highFivesGuys(void) const;

	private:

};

std::ostream &			operator<<( std::ostream & o, FragTrap const & i );

#endif /* ******************************************************** FRAGTRAP_H */