/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:20:37 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/12 14:59:29 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include "easyfind.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::for_each;

void    printInt(int i) {
    cout << ' ' << i;
}

int main() {
    int ints[] = {1, 2, 2, 3, 3, 3, 5, 5, 5, 6};
    vector<int>    v(ints, ints + sizeof(ints) / sizeof(int));
    list<int>      l(ints, ints + sizeof(ints) / sizeof(int));
    vector<int>::const_iterator  vIt;
    vector<int>::const_iterator  vIt2;
    list<int>::const_iterator    lIt;

    cout << "The vector contains:";
    for_each(v.begin(), v.end(), printInt);
    cout << endl;
    vIt = easyfind(v, 3);
    if (vIt != v.end())
        cout << "Found 3 in the vector ad index: " << getIndex(v, vIt) << endl;
    cout << "The list contains:";
    for_each(l.begin(), l.end(), printInt);
    cout << endl;
    lIt = easyfind(l, 3);
    if (vIt != v.end())
        cout << "Found 3 in the list at index: " << getIndex(l, lIt) << endl;
    try {
        cout << "The vector contains:";
        for_each(v.begin(), v.end(), printInt);
        cout << endl;
        vIt2 = easyfind(v, 42);
    }
    catch (NotFoundException & e) {
        cout << e.what() << endl;
    }
}