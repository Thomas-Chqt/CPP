/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:42:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/02 15:38:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\033[0;32m" << "Tests bureaucrat level 20 : " << "\033[0m" << std::endl;
    {
        try
        {
            Bureaucrat burr("Jimmy", 20);
            std::cout << burr << std::endl;
            burr.incrementGrade();
            std::cout << burr << std::endl;
            burr.decrementGrade();
            std::cout << burr << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "Tests bureaucrat level 0" << "\033[0m" << std::endl;
    {
        try
        {
            Bureaucrat burr("Kim", 0);
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "Tests bureaucrat level 200" << "\033[0m" << std::endl;
    {
        try
        {
            Bureaucrat burr("Mike", 200);
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;
    
    std::cout << "\033[0;32m" << "Tests bureaucrat level 1" << "\033[0m" << std::endl;
    {
        try
        {
            Bureaucrat burr("Gus", 1);
            std::cout << burr << std::endl;
            burr.incrementGrade();
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "Tests bureaucrat level 150" << "\033[0m" << std::endl;
    {
        try
        {
            Bureaucrat burr("Lalo", 150);
            std::cout << burr << std::endl;
            burr.decrementGrade();
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }

    return 0;
}
