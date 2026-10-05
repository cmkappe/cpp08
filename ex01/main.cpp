/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:42:39 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/05 16:25:43 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        //std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "error: " << e.what() << std::endl;
    }

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

    try
    {
        Span tooSmall(2);
        tooSmall.addNumber(42);
        std::cout << tooSmall.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "tooSmall: " << e.what() << std::endl;
    }

    try
    {
        Span full(3);
        full.addNumber(1);
        full.addNumber(2);
        full.addNumber(3);
        full.addNumber(4);
    }
    catch (const std::exception& e)
    {
        std::cerr << "full: " << e.what() << std::endl;
    }

    return 0;
}
