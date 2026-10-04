/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:27:52 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/04 18:16:26 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>

int main() {

    std::vector<int> v = {1, 2, 3};
    // list
    // deque
    // array
    // forward_list

    try {
    std::vector<int>::const_iterator it = easyfind(v, 2);
    std::cout << "The value in the vector container is found at the index: "
          << std::distance(v.cbegin(), it) << std::endl;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(v, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << "\n" << std::endl;
    }
    
  return 0;
}