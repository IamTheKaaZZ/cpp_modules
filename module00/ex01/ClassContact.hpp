/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:10:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/08 17:18:05 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class	Contact {

	static size_t	_nbInst;
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickname;
	std::string		_phoneNumber;
	std::string		_darkestSecret;

};