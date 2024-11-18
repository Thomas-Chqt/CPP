/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:47:36 by tchoquet          #+#    #+#             */
/*   Updated: 2024/04/29 20:37:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <exception>

int main(int argc, char* argv[])
{
    try
    {
        PmergeMe pmergeMe;

        for (int i = 1; i < argc; i++)
        {
            std::istringstream istream(argv[i]);
            unsigned int num;
            istream >> num;
            if (istream.fail() || !istream.eof())
                throw std::runtime_error(std::string(argv[i]) + ": bad argument");
            pmergeMe.push_back(num);
        }

        std::cout << "Before: " << pmergeMe << std::endl;

        float vectorTime;
        float listTime;

        pmergeMe.sort(vectorTime, listTime);

        std::cout << "After:  " << pmergeMe << std::endl;

        std::cout << "Time to process a range of " << pmergeMe.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
        std::cout << "Time to process a range of " << pmergeMe.size() << " elements with std::list   : " << listTime << " us" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << argv[0] << ": " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
