/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:18:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/21 11:18:41 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		virtual ~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );
		std::string		getName(void) const;
		unsigned int	getHP(void) const;
		unsigned int	getEP(void) const;
		unsigned int	getAD(void) const;
		void			attack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	protected:

		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_maxHP;
		unsigned int	_energyPoints;
		unsigned int	_maxEP;
		unsigned int	_attackDamage;

};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */