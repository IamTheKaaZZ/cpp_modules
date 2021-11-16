/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:37:59 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/16 11:30:44 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {

public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void		announce(void) const;
	std::string	getName(void) const;
	void		setName(std::string name);

private:

	std::string	_name;

};

	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);
	Zombie*	zombieHorde(int N, std::string name);

#endif