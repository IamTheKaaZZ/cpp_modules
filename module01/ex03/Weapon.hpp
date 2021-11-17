/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:26:01 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/17 10:42:41 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
using std::string;

class Weapon {

public:

	Weapon(void);
	Weapon(string type);
	~Weapon(void);
	string const &	getType(void) const;
	void			setType(string name);


private:

	string	_type;

};

#endif