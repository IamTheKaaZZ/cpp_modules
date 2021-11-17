/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:32:14 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/17 17:26:50 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <map>
# include <string>

using std::string;

enum level_code {
	eDebug,
	eInfo,
	eWarning,
	eError,
	eWTF
};

class Karen {

	public:
		//Map a string to a `void Karen::function(void) const`
		typedef std::map<string,void(Karen::*)()const> StrToF;
		Karen(void);
		~Karen(void);
		void			complain(std::string level) const;
		void			filter(std::string level) const;
		const StrToF&	getMap(void) const;

	private:

		StrToF	_fmap;
		void		debug(void) const;
		void		info(void) const;
		void		warning(void) const;
		void		error(void) const;
		level_code	_hashstr(string const& levelstr) const;

};

#endif