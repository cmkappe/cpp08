/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:45:31 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/05 16:22:29 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <limits>
#include <stdexcept>
#include <algorithm>
#include <vector>

Span::Span(const unsigned int &N) : _N(N) {
  if (N < 2) {
    throw std::runtime_error("N needs to be above 1");
  }
  v.reserve(N);
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (v.size() >= _N)
        throw std::runtime_error("Span is full");

    v.push_back(number);
}

long long Span::shortestSpan() const {
    if (v.size() < 2)
        throw std::runtime_error("Need more numbers to calculate span");
    
    std::vector<int> tmp(v);
    
    // sort the copy, so we only look at neighbors
    std::sort(tmp.begin(), tmp.end());
    
    // reserve biiig space for "shortest", can only get smaller
    long long shortest = std::numeric_limits<long long>::max();
    
    for (size_t i = 1; i < tmp.size(); ++i){
        long long span = static_cast<long long>(tmp[i])
                       - static_cast<long long>(tmp[i - 1]);

        // compare current shortest value with new span, keep the smaller one
        shortest = std::min(shortest, span);
    }
    return shortest;
}


long long Span::longestSpan() const {
    
    if (v.size() < 2)
        throw std::runtime_error("Need more numbers to calculate span");
        
    std::pair<std::vector<int>::const_iterator,
              std::vector<int>::const_iterator> minmax;
              
    minmax = std::minmax_element(v.begin(), v.end());
    return (static_cast<long long>(*minmax.second)
         - static_cast<long long>(*minmax.first));
}




