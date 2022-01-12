/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:08:16 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/12 17:58:36 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <vector>

struct RandomGenerator {
    int maxValue;
    RandomGenerator(int max) :
            maxValue(max) {
    }
    int operator()() {
        return rand() % maxValue;
    }
};

using std::cout;
using std::endl;

int main() {
    Span    sp(5);
    sp.addNumber(11);
    sp.addNumber(5);
    sp.addNumber(9);
    sp.addNumber(3);
    sp.addNumber(17);
    cout << sp;
    std::vector<int>    reallyBig(10000);
    std::generate(reallyBig.begin(), reallyBig.end(), RandomGenerator(100));
    Span    BigBoi(10000);
    BigBoi.addNumber(reallyBig.begin(), reallyBig.end());
    cout << BigBoi;
    try {
        sp.addNumber(69);
    }
    catch (Span::LimitReached & e) {
        cout << e.what() << endl;
    }
    std::vector<int>    errorTest(100);
    std::generate(errorTest.begin(), errorTest.end(), RandomGenerator(100));
    Span    error(99);
    try {
        cout << error;
    }
    catch (Span::NoSpan & e) {
        cout << e.what() << endl;
    }
    try {
        error.addNumber(errorTest.begin(), errorTest.end());
    }
    catch (Span::RangeTooBig & e) {
        cout << e.what() << endl;
    }
}