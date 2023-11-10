/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:42:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/07 14:26:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\033[0;32m" << "Tests form required grade 20 and bureaucrat grade 10: " << "\033[0m" << std::endl;
    {
        try
        {
            Bureaucrat bur("Jimmy", 10);
            Form form("Job application", 20, 20);
            std::cout << form << std::endl;
            bur.signForm(form);
            std::cout << form << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "Tests form required grade 0: " << "\033[0m" << std::endl;
    {
        try
        {
            Form form("Visa extension refusal", 0, 0);
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "Tests form required grade 200: " << "\033[0m" << std::endl;
    {
        try
        {
            Form form("NDA agreement", 200, 200);
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "Tests form required grade 30 and bureaucrat grade 40: " << "\033[0m" << std::endl;
    {
        try
        {
            Bureaucrat bur("Kim", 40);
            Form form("Visa approval", 30, 30);
            std::cout << form << std::endl;
            bur.signForm(form);
            std::cout << form << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}
