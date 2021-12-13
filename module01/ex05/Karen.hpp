/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:32:14 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/13 11:49:04 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <map>
# include <string>

using std::string;

class Karen {

	public:
		struct s_lookup {
			string key;
			void(Karen::*fp)()const;
			s_lookup() {};
			s_lookup(string const & key, void(Karen::*fp)()const) {
				this->key = key;
				this->fp = fp;
			};
		};
		Karen(void);
		~Karen(void);
		void			complain(std::string level) const;

	private:

		s_lookup	_func_lookup_table[5];
		void		debug(void) const;
		void		info(void) const;
		void		warning(void) const;
		void		error(void) const;
};

#endif