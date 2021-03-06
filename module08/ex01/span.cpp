/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:57:21 by bcosters          #+#    #+#             */
/*   Updated: 2022/04/25 11:40:28 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;

//------------------------------------------//
Span::Span() : _maxN(0), _currentRange(0) {
    cout << "Default constructor called" << endl;
}

Span::Span(unsigned int const & N) : _maxN(N), _currentRange(0) {
    cout << "Parameter constructor called" << endl;
}

Span::Span(Span const & src) :
    _maxN(src._maxN),
    _currentRange(src._currentRange),
    _v(src._v) {
    cout << "Copy constructor called" << endl;
}

Span::~Span() {
    cout << "Destructor called" << endl;
}

//------------------------------------------//
Span &      Span::operator=(const Span & rhs) {
    if (this != &rhs) {
        this->_maxN = rhs._maxN;
        this->_currentRange = rhs._currentRange;
        this->_v.clear();
        this->_v.insert(_v.end(), rhs._v.begin(), rhs._v.end());
    }
    return *this;
}

//------------------------------------------//
void        Span::addNumber(int const & i) {
    if (this->_currentRange == this->_maxN) {
        throw LimitReached();
    }
    this->_v.push_back(i);
    this->_currentRange++;
}

void        Span::addNumber(vIT const & b, vIT const & e) {
    if (this->_currentRange == this->_maxN) {
        throw LimitReached();
    }
    int count = std::distance(b, e);
    if (this->_currentRange + count > this->_maxN) throw RangeTooBig();
    this->_v.insert(_v.end(), b, e);
    this->_currentRange += count;
}

unsigned int    Span::shortestSpan() {
    if (this->_currentRange <= 1) throw NoSpan();
    std::vector<int>::const_iterator  it = this->_v.begin();
    std::vector<int>::const_iterator  ite = this->_v.end();
    unsigned int    span = UINT_MAX;
    unsigned int    diff;
    for(; it != ite; it++) {
        if (it + 1 != ite -1) {
            diff = static_cast<unsigned int>(std::abs(*it - *(it + 1)));
            if (diff <= span) span = diff;
        }
    }
    return span;
}

unsigned int    Span::longestSpan() {
    if (this->_currentRange <= 1) throw NoSpan();
    std::vector<int>::const_iterator  it = this->_v.begin();
    std::vector<int>::const_iterator  ite = this->_v.end();
    unsigned int    span = 0;
    unsigned int    diff;
    for(; it != ite; it++) {
        if (it + 1 != ite -1) {
            diff = static_cast<unsigned int>(std::abs(*it - *(it + 1)));
            if (diff >= span) span = diff;
        }
    }
    return span;
}

//------------------------------------------//
std::ostream &      operator<<(std::ostream & o, Span & s) {
    std::vector<int>::const_iterator    it = s.getVector().begin();
    std::vector<int>::const_iterator    ite = s.getVector().end();
    o << "Max range is " << s.getN() << endl;
    o << "Current range is " << s.getCurrentRange() << endl;
    o << "The vector contains:";
    for(;it != ite; it++) {
        o << ' ' << *it;
    }
    o << endl;
    o << "The shortest span is " << s.shortestSpan() << endl;
    o << "The longest span is " << s.longestSpan() << endl;
    return o;
}

//------------------------------------------//
const char * Span::LimitReached::what() const throw() {
    return ("Max amount of ints reached.");
}
const char * Span::RangeTooBig::what() const throw() {
    return ("Attempting to add a range that would exceed the max amount of ints.");
}
const char * Span::NoSpan::what() const throw() {
    return ("Cannot calculate the span.");
}