/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:42:39 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/05 17:33:21 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <climits>

static const char* RESET = "\033[0m";
static const char* BOLD = "\033[1m";
//static const char* CYAN = "\033[36m";
//static const char* GREEN = "\033[32m";
//static const char* RED = "\033[31m";
static const char* YELLOW = "\033[33m";


int main()
{
    std::cout << YELLOW << BOLD << "\nTest for shortest and longest" << RESET << std::endl;
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "error: " << e.what() << std::endl;
    }

    std::cout << YELLOW << BOLD << "\nTesting original & copy" << RESET << std::endl;
    Span original(5);
    original.addNumber(10);
    original.addNumber(20);

    Span copy(original);

    std::cout << "Original: "
            << original.longestSpan() << std::endl;

    std::cout << "Copy: "
            << copy.longestSpan() << std::endl;

    std::cout << YELLOW << BOLD << "\nTest with duplicates" << RESET << std::endl;
    Span duplicates(5);
    duplicates.addNumber(42);
    duplicates.addNumber(10);
    duplicates.addNumber(42);
    duplicates.addNumber(100);

    std::cout << "Duplicate shortest: "
            << duplicates.shortestSpan() << std::endl;

    std::cout << "Duplicate longest: "
            << duplicates.longestSpan() << std::endl;
    // Duplicate shortest: 0
    // Duplicate longest: 90
    
    std::cout << YELLOW << BOLD << "\nTest with duplicates & negative numbers" << RESET << std::endl;
    try {
        Span sp2(4);
        sp2.addNumber(42);
        sp2.addNumber(42);
        sp2.addNumber(-42);
        sp2.addNumber(420);

        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "error: " << e.what() << std::endl;
    }

    std::cout << YELLOW << BOLD << "\nTest INT_MIN & INT_MAX" << RESET << std::endl;
    Span extremes(2);

    extremes.addNumber(INT_MIN);
    extremes.addNumber(INT_MAX);

    std::cout << "Extreme span: "
            << extremes.longestSpan() << std::endl;
    // expected 4294967295

    std::cout << YELLOW << BOLD << "\nTest Span too small" << RESET << std::endl;
    try{
        Span tooSmall(2);
        tooSmall.addNumber(42);

        tooSmall.shortestSpan();
    }
    catch (const std::exception &e){
        std::cerr << "tooSmall shortest: "
                << e.what() << std::endl;
    }
    try{
        Span tooSmall(2);
        tooSmall.addNumber(42);

        tooSmall.longestSpan();
    }
    catch (const std::exception &e){
        std::cerr << "tooSmall longest: "
                << e.what() << std::endl;
    }

    std::cout << YELLOW << BOLD << "\nTest Array already full" << RESET << std::endl;
    try{
        Span full(3);
        full.addNumber(1);
        full.addNumber(2);
        full.addNumber(3);
        full.addNumber(4);
    }
    catch (const std::exception& e){
        std::cerr << "full: " << e.what() << std::endl;
    }

    std::cout << YELLOW << BOLD << "\nTest addRange()" << RESET << std::endl;
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(5);
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(50);

    Span rangeSpan(5);

    rangeSpan.addRange(numbers.begin(), numbers.end());

    std::cout << "Range shortest: "
            << rangeSpan.shortestSpan() << std::endl;

    std::cout << "Range longest: "
            << rangeSpan.longestSpan() << std::endl;

    // Span capacity = 3
    // range size    = 4
    
    std::cout << YELLOW << BOLD << "\nTest addRange() capacity protection" << RESET << std::endl;
    try
    {
        std::vector<int> numbers;

        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);

        Span small(3);

        small.addRange(numbers.begin(), numbers.end());
    }
    catch (const std::exception &e)
    {
        std::cerr << "addRange capacity: "
                << e.what() << std::endl;
    }

    std::cout << YELLOW << BOLD << "\nTest thousands" << RESET << std::endl;

    std::vector<int> manyNumbers;
    for (int i = 0; i < 100000; ++i)
        manyNumbers.push_back(i);
   
    Span huge(100000);
    huge.addRange(manyNumbers.begin(), manyNumbers.end());

    std::cout << "10,0000 numbers:" << std::endl;
    std::cout << "shortest = "
            << huge.shortestSpan() << std::endl;

    std::cout << "longest = "
            << huge.longestSpan() << std::endl;

    // shortest = 1
    // longest = 99999    

    
    return 0;
}
