/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:27:52 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/06 15:56:32 by ckappe           ###   ########.fr       */
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

static const char* RESET = "\033[0m";
static const char* BOLD = "\033[1m";
// static const char* CYAN = "\033[36m";
static const char* GREEN = "\033[32m";
static const char* RED = "\033[31m";
static const char* YELLOW = "\033[33m";

int main() {

    //--- Coontainer ---
    std::vector<int> v = {1, 2, 3};
    std::list<int> l = {4, 5, 6};
    std::deque<int> d = {7, 8, 9};
    std::array<int, 3> a = {10, 11, 12};
    std::forward_list<int> f = {13, 14, 15};

    //--- Valid Search ---
    std::cout << "\n" << BOLD << YELLOW << "--- Valid Search ---" << RESET << std::endl;
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
    std::forward_list<int>::const_iterator it = easyfind(f, 13);
    std::cout
        << "The value in the forward_list container is found at the index: "
        << std::distance(f.cbegin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n" << std::endl;

    std::cout << BOLD << "Value is the first element:" << RESET << std::endl;
    try {
        std::vector<int> v = {42, 7, 10};
        std::vector<int>::const_iterator it = easyfind(v, 42);
        std::cout << " expected index: 0" << std::endl;
        std::cout << GREEN << " valid, found value: " << *it
                  << " at index " << std::distance(v.cbegin(), it) << RESET << std::endl;
    } catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << BOLD << "Value is the last element:" << RESET << std::endl;
    try {
        std::vector<int> v = {7, 10, 42};
        std::vector<int>::const_iterator it = easyfind(v, 42);
        std::cout << " expected index: 2" << std::endl;
        std::cout << GREEN << " valid, found value: " << *it
                  << " at index " << std::distance(v.cbegin(), it) << RESET << std::endl;
    } catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    // should return first matching element
    std::cout << BOLD << "Duplicate values:" << RESET << std::endl;
    try {
        std::vector<int> v = {5, 5, 5, 10};
        std::vector<int>::const_iterator it = easyfind(v, 5);
        std::cout << " expected index: 0" << std::endl;
        std::cout << GREEN << " valid, found value: " << *it
                  << " at index " << std::distance(v.cbegin(), it) << RESET << std::endl;
    } catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << BOLD << "Container with const elements:" << RESET << std::endl;
    try {
        const std::vector<int> v = {1, 2, 3};
        std::vector<int>::const_iterator it = easyfind(v, 2);
        std::cout << GREEN << " valid, found value: " << *it
                  << " at index " << std::distance(v.cbegin(), it) << RESET << std::endl;
    } catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    
    //--- Non Valid Search ---
    std::cout << BOLD << RED << "\n\n--- Non Valid Search ---" << RESET << std::endl;
    try { easyfind(v, 42); } catch (std::exception &e) { std::cout << "vector: " << e.what() << std::endl; }
    try { easyfind(l, 111); } catch (std::exception &e) { std::cout << "list: " << e.what() << std::endl; }
    try { easyfind(d, 1234); } catch (std::exception &e) { std::cout << "deque: " << e.what() << std::endl; }
    try { easyfind(a, 10000); } catch (std::exception &e) { std::cout << "array: " << e.what() << std::endl; }
    try { easyfind(f, 3425); } catch (std::exception &e) { std::cout << "forward_list: " << e.what() << std::endl <<std::endl; }
    
    std::cout << BOLD << "empty container check:" << RESET << std::endl;
    try {
        std::vector<int> empty;
        easyfind(empty, 5);
    } catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    
  return 0;
}
