/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:53:13 by bcosters          #+#    #+#             */
/*   Updated: 2022/04/22 16:29:30 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>

int	main() {
	srand(time(0));
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
	delete ptr1;
	delete ptr2;
	delete ptr3;
	return 0;
}