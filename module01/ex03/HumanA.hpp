/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:36:22 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/17 11:12:44 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

using std::string;
class HumanA {

public:

	HumanA(string name, Weapon& w);
	~HumanA(void);
	void	attack(void) const;

private:

	string	_name;
	Weapon*	_w;
	HumanA(void);

};

#endif