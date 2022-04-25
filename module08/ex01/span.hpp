/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:11:27 by bcosters          #+#    #+#             */
/*   Updated: 2022/04/25 11:40:54 by bcosters         ###   ########.fr       */
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
            virtual const char * what() const throw();
        };
        class RangeTooBig : public std::exception {
            public:
            virtual const char * what() const throw();
        };
        class NoSpan : public std::exception {
            public:
            virtual const char * what() const throw();
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
        
};

std::ostream &      operator<<(std::ostream & o, Span & s);

#endif