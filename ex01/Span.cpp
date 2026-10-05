/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:45:31 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/05 01:55:19 by ckappe           ###   ########.fr       */
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

