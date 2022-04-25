/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:55:13 by bcosters          #+#    #+#             */
/*   Updated: 2022/04/25 12:06:00 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <algorithm>
#include <ios>
#include <iostream>
#include <stack>

using std::cout;
using std::endl;

int main() {
    MutantStack<int> mt;

    mt.push(7);
    mt.push(69);
    cout << std::boolalpha << "Is MutantStack empty? -> " << mt.empty() << endl;
    cout << mt;
    mt.pop();
    cout << mt;
    mt.pop();
    cout << mt;
    cout << std::boolalpha << "Is MutantStack empty? -> " << mt.empty() << endl;
    mt.push(7);
    mt.push(69);
    mt.push(96);
    mt.push(42);
    mt.push(-42);
    cout << mt;
    cout << std::boolalpha << "Is MutantStack empty? -> " << mt.empty() << endl;
    MutantStack<int>::iterator  it = mt.begin();
    MutantStack<int>::iterator  ite = mt.end();
    cout << "The stack contains: ";
    for( ; it != ite; it++) {
        cout << ' ' << *it;
    }
    cout << endl;
    it = mt.begin();
    ite = mt.end();
    cout << "The stack (order of underlying container) contains: ";
    std::reverse(it, ite);
    for( ; it != ite; it++) {
        cout << ' ' << *it;
    }
    cout << endl;

	std::stack<int> s(mt);
}