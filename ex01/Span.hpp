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

// _N is maximum number of values allowed
// v is the actual storage
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


        void        addNumber(int number);

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

/* Develop a Span class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.

This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.

Next, implement two member functions: shortestSpan() and longestSpan()
They will respectively find out the shortest span or the longest span (or distance, if
you prefer) between all the numbers stored, and return it. If there are no numbers stored,
or only one, no span can be found. Thus, throw an exception.

Of course, you will write your own tests, and they will be far more thorough than the
ones below. Test your Span with at least 10,000 numbers. More would be even better. */
