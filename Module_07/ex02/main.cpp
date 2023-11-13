/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:00:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/13 15:35:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750
int main()
{
    std::cout << "\033[0;32m" << "Subject exemple" << "\033[0m" << std::endl;
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "string array" << "\033[0m" << std::endl;
    {
        Array<std::string> strArray(10);

        for (unsigned int i = 0; i < strArray.size(); i++)
            std::cout << '\'' << strArray[i] << '\'' << std::endl;
        
        std::cout << "Filling array..." << std::endl;
        for (unsigned int i = 0; i < strArray.size(); i++)
            strArray[i] = "Hello";

        for (unsigned int i = 0; i < strArray.size(); i++)
            std::cout << '\'' << strArray[i] << '\'' << std::endl;
        
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "const string array" << "\033[0m" << std::endl;
    {
        const Array<std::string> strArray(10);

        for (unsigned int i = 0; i < strArray.size(); i++)
            std::cout << '\'' << strArray[i] << '\'' << std::endl;
        
        std::cout << "Filling array..." << std::endl;
        for (unsigned int i = 0; i < strArray.size(); i++)
            strArray[i] = "Hello";

        for (unsigned int i = 0; i < strArray.size(); i++)
            std::cout << '\'' << strArray[i] << '\'' << std::endl;
        
    }
    std::cout << std::endl;

    return 0;
}