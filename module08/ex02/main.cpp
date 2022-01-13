/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:55:13 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/13 15:47:57 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <algorithm>
#include <ios>
#include <iostream>

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
    cout << "The stack (in order of its underlying container) contains: ";
    for( ; it != ite; it++) {
        cout << ' ' << *it;
    }
    cout << endl;
    it = mt.begin();
    ite = mt.end();
    cout << "The stack (actual order) contains: ";
    std::reverse(it, ite);
    for( ; it != ite; it++) {
        cout << ' ' << *it;
    }
    cout << endl;
}