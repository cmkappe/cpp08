/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 17:36:43 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/06 18:05:51 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <exception>
#include <stack>
#include <deque>

static const char* RESET = "\033[0m";
static const char* BOLD = "\033[1m";
//static const char* CYAN = "\033[36m";
//static const char* GREEN = "\033[32m";
//static const char* RED = "\033[31m";
static const char* YELLOW = "\033[33m";

int main()
{
    std::cout << YELLOW << BOLD << "\nTest basic stack operations" << RESET << std::endl;

    try{
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top: " << mstack.top() << std::endl;

        mstack.pop();

        std::cout << "Size after pop: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "Top: " << mstack.top() << std::endl;

        std::cout << "Size: " << mstack.size() << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << "error: " << e.what() << std::endl;
    }

    std::cout << YELLOW << BOLD << "\nTest iterators" << RESET << std::endl;
    try {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        // Test increment and decrement
        ++it;
        --it;

        std::cout << "Iterator contents:" << std::endl;

        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "error: " << e.what() << std::endl;
    }

    std::cout << YELLOW << BOLD << "\nTest iterator with for loop" << RESET << std::endl;
    try {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        for (MutantStack<int>::iterator it = mstack.begin();
             it != mstack.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "error: " << e.what() << std::endl;
    }

    
    std::cout << YELLOW << BOLD << "\nTest copy into std::stack" << RESET << std::endl;
    try {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::stack<int> normalStack(mstack);

        std::cout << "Normal stack top: "
                  << normalStack.top() << std::endl;

        std::cout << "Normal stack size: "
                  << normalStack.size() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "error: "
                  << e.what() << std::endl;
    }


    std::cout << YELLOW << BOLD << "\nTest iterator modification" << RESET << std::endl;
    try {
        MutantStack<int> mstack;

        mstack.push(10);
        mstack.push(20);
        mstack.push(30);

        MutantStack<int>::iterator it = mstack.begin();

        *it = 100;

        for (MutantStack<int>::iterator current = mstack.begin();
             current != mstack.end();
             ++current)
        {
            std::cout << *current << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "error: "
                  << e.what() << std::endl;
    }


    std::cout << YELLOW << BOLD << "\nTest empty stack" << RESET << std::endl;
    try {
        MutantStack<int> empty;

        std::cout << "Empty: " << (empty.empty() ? "yes" : "no") << std::endl;
        std::cout << "Size: " << empty.size() << std::endl;

        if (empty.begin() == empty.end())
            std::cout << "begin() == end()" << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << "error: "
                  << e.what() << std::endl;
    }
    return 0;
}
