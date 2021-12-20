/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:53:13 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 15:52:58 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

using std::cout;
using std::endl;

int	main() {
	Base*	ptr1 = generate();
	Base*	ptr2 = generate();
	Base*	ptr3 = generate();
	identify(ptr1);
	identify(ptr2);
	identify(ptr3);
	identify(NULL);
	identify(*ptr1);
	identify(*ptr2);
	identify(*ptr3);
	return 0;
}