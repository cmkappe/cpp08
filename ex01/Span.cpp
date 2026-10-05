/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:45:31 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/05 15:54:03 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <limits>
#include <stdexcept>
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
    std::sort(tmp.begin(), tmp.end());
    
    // reserve biiig space for sSpan, can only get smaller
    long long sSpan = std::numeric_limits<long long>::max();
    for (size_t i = 1; i < tmp.size(); ++i){
        long int second = static_cast<long int>(tmp[i]);
        long int first = static_cast<long int>(tmp[i - 1]);
        long int result = std::labs(second - first);
        sSpan = std::min<long>(sSpan, std::labs(result));
    }

    return sSpan;
}





