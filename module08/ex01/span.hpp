/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:11:27 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/12 17:55:13 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <exception>
# include <algorithm>
# include <iterator>
# include <stack>

typedef std::vector<int>::iterator vIT;

class Span {

    public:
        Span(unsigned int const & N);
        Span(Span const & src);
        ~Span();

        class LimitReached : public std::exception {
            public:
            virtual const char * what() const throw() {
                return ("Max amount of ints reached.");
            }
        };
        class RangeTooBig : public std::exception {
            public:
            virtual const char * what() const throw() {
                return ("Attempting to add a range that would exceed the max amount of ints.");
            }
        };
        class NoSpan : public std::exception {
            public:
            virtual const char * what() const throw() {
                return ("Cannot calculate the span.");
            }
        };
        Span &  operator=(Span const & rhs);
        void    addNumber(int const & i);
        void    addNumber(vIT const & b, vIT const & e);
        unsigned int    shortestSpan();
        unsigned int    longestSpan();
        unsigned int    getN() const { return this->_maxN; };
        unsigned int    getCurrentRange() const { return this->_currentRange; };
        std::vector<int> const &    getVector() const { return this->_v; };
        
    private:
        Span();
        void                _getSpans();
        unsigned int        _maxN;
        unsigned int        _currentRange;
        std::vector<int>    _v;
        std::vector<unsigned int>    _spans;
        
};

std::ostream &      operator<<(std::ostream & o, Span & s);

#endif