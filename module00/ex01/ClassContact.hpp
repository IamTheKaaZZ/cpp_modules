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

	static int		nbInst;
	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_phone_number;
	std::string		_darkest_secret;

};