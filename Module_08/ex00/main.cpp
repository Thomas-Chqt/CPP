/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:42:34 by tchoquet          #+#    #+#             */
/*   Updated: 2024/01/13 17:43:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec1;

    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(5);
    vec1.push_back(7);
    vec1.push_back(6);
    vec1.push_back(-2);
    vec1.push_back(1);

    try
    {
        std::cout << easyfind(vec1, -2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::list<int> list1;

    list1.push_back(1);
    list1.push_back(3);
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(6);
    list1.push_back(-2);
    list1.push_back(1);

    try
    {
        std::cout << easyfind(list1, -2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::vector<int> vec2;

    vec2.push_back(1);
    vec2.push_back(3);
    vec2.push_back(5);
    vec2.push_back(7);
    vec2.push_back(6);
    vec2.push_back(-2);
    vec2.push_back(1);

    try
    {
        std::cout << easyfind(vec2, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::list<int> list2;

    list2.push_back(1);
    list2.push_back(3);
    list2.push_back(5);
    list2.push_back(7);
    list2.push_back(6);
    list2.push_back(-2);
    list2.push_back(1);

    try
    {
        std::cout << easyfind(list2, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    
}
