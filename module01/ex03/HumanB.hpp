/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:44:53 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/17 10:55:34 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

using std::string;
class HumanB {

public:

	HumanB(string name);
	~HumanB(void);
	void	attack(void) const;
	void	setWeapon(Weapon& w);

private:

	string	_name;
	Weapon*	_w;
	HumanB(void);

};

#endif