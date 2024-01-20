/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:22:48 by tchoquet          #+#    #+#             */
/*   Updated: 2024/01/13 19:39:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "Span.hpp"

int main()
{
    {
        Span sp = Span(5);

        try
        {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }


    {
        Span sp = Span(5);
        int nbrs[] = {6, 3, 17, 9, 11};
        try
        {
            sp.addNumber(nbrs, nbrs + sizeof(nbrs) / sizeof(nbrs[0]));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        Span sp = Span(5);
        std::vector<int> vec;

        vec.push_back(6);
        vec.push_back(3);
        vec.push_back(17);
        vec.push_back(9);
        vec.push_back(11);

        try
        {
            sp.addNumber(vec.begin(), vec.end());
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    
    {
        srand(time(NULL));
        Span sp = Span(300000);

        try
        {
            for (int i = 0; i < 300000; i++)
            {
                sp.addNumber(rand());
            }
            
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        int nbrs[] = {6, 3, 17, 3, 11};
        Span sp = Span(sizeof(nbrs) / sizeof(nbrs[0]));
        try
        {
            sp.addNumber(nbrs, nbrs + sizeof(nbrs) / sizeof(nbrs[0]));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
}
