/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:48:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/30 11:28:26 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{

	public:

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();

		DiamondTrap &		operator=( DiamondTrap const & rhs );
		void			attack(std::string const & target);
		void			whoAmI(void) const;
		std::string		getName(void) const;

	private:

		std::string		_name;

};

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i );

#endif /* ***************************************************** DIAMONDTRAP_H */