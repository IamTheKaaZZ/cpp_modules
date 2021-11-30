/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:22:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/30 10:21:02 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

	public:

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );
		void			setName(std::string name);
		void			setHp(void);
		void			setEp(void);
		void			setAd(void);
		void			guardGate(void);

	protected:

		bool		_gateKeeperMode;

};

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i );

#endif /* ******************************************************** SCAVTRAP_H */