/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:53:13 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 15:24:28 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

using std::uintptr_t;
using std::cout;
using std::endl;

uintptr_t	serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int	main() {
	Data d("Cookies", 42);
	cout << d << endl;
	Data*	dptr = &d;
	cout << dptr << endl;
	uintptr_t	ser = serialize(dptr);
	cout << ser << endl;
	Data*	eptr = deserialize(ser);
	cout << eptr << endl;
	cout << *eptr << endl;
	cout << "NULL test" << endl;
	Data*	fptr = NULL;
	ser = serialize(fptr);
	cout << ser << endl;
	cout << deserialize(ser) << endl;
	return 0;
}