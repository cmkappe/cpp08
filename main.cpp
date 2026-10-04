/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:27:52 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/04 18:24:04 by ckappe           ###   ########.fr       */
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
    std::list<int> l = {4, 5, 6};
    std::deque<int> d = {7, 8, 9};
    std::array<int, 3> a = {10, 11, 12};
    // forward_list

    try {
    std::vector<int>::const_iterator it = easyfind(v, 2);
    std::cout << "The value in the vector container is found at the index: "
          << std::distance(v.cbegin(), it) << std::endl;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
    std::list<int>::const_iterator it = easyfind(l, 5);
    std::cout << "The value in the list container is found at the index: "
          << std::distance(l.cbegin(), it) << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    try {
        std::deque<int>::const_iterator it = easyfind(d, 9);
        std::cout << "The value in the deque container is found at the index: "
            << std::distance(d.cbegin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::array<int, 3>::const_iterator it = easyfind(a, 12);
        std::cout << "The value in the array container is found at the index: "
            << std::distance(a.cbegin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    


    
    try {
        easyfind(v, 100);
        easyfind(l, 500);
        easyfind(d, 900);
        easyfind(a, 1200);
    } catch (std::exception &e) {
        std::cout << e.what() << "\n" << std::endl;
    }
    
  return 0;
}