#pragma once

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>

#include <vector>

class Span {
    private:
        unsigned int        _N;
        std::vector<int>    v;

    public:
        // '= delete' it's not possible to have an empty construcor
        Span() = delete;
        Span(const unsigned int &N);
        ~Span();
        // '= default' uses cpp default implementation
        // Span(const Span &other) = default;
        // Span operator=(const Span &other) = delete;

        void addNumber(int number);
    
        template <typename Iterator>
        void        addRange(Iterator begin, Iterator end);

        long long   shortestSpan() const;
        long long   longestSpan() const;

        //void print() const;
};