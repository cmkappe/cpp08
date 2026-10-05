/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 17:36:43 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/05 18:04:55 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

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

        std::cout << "Top: "
                  << mstack.top() << std::endl;

        mstack.pop();

        std::cout << "Size after pop: "
                  << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "Top: "
                  << mstack.top() << std::endl;

        std::cout << "Size: "
                  << mstack.size() << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << "error: "
                  << e.what() << std::endl;
    }

    return 0;
}
