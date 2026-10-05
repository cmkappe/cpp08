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
        Span() = delete;
        Span(const unsigned int &N);
        ~Span();
        // Span(const Span &other) = default;
        // Span operator=(const Span &other) = delete;

    // void addNumber(int num);
    // shortestSpan
    // longestSpan
};