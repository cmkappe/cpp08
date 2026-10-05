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


class Span {
    private:
        unsigned int        _N;
        std::vector<int>    v;

    public:
        // '= delete' it's not possible to have an empty construcor
        // '= default' uses cpp default implementation
        Span() = delete;
        Span(const unsigned int &N);
        ~Span();
        Span(const Span &other) = default;
        Span operator=(const Span &other) = delete;

        void addNumber(int number);

        long long   shortestSpan() const;
        long long   longestSpan() const;

        template <typename It>
        void addRange(It first, It last)
        {
            if (std::distance(first, last) > 
            static_cast<long long>(_N - v.size()))
                throw std::runtime_error("Not enough capacity to add range");

            v.insert(v.end(), first, last);
        }
};