/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:42:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/05 20:19:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\033[0;32m" << "Bureaucrat grade 150: " << "\033[0m" << std::endl;
    {
        try
        {
            Bureaucrat bur("Jimmy", 150);

            {
                ShrubberyCreationForm form("garden");
                bur.executeForm(form);
            }
            {
                RobotomyRequestForm form("kim");
                bur.executeForm(form);
            }
            {
                PresidentialPardonForm form("lalo");
                bur.executeForm(form);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;


    std::cout << "\033[0;32m" << "Bureaucrat grade 1: " << "\033[0m" << std::endl;
    {
        try
        {
            Bureaucrat bur("kim", 1);

            {
                ShrubberyCreationForm form("beach");
                bur.executeForm(form);
            }
            {
                RobotomyRequestForm form("jimmy");
                bur.executeForm(form);
            }
            {
                PresidentialPardonForm form("lalo");
                bur.executeForm(form);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;


    std::cout << "\033[0;32m" << "Bureaucrat grade 100: " << "\033[0m" << std::endl;
    {
        try
        {
            Bureaucrat bur("lalo", 100);

            {
                ShrubberyCreationForm form("garden");
                bur.executeForm(form);
            }
            {
                RobotomyRequestForm form("jimmy");
                bur.executeForm(form);
            }
            {
                PresidentialPardonForm form("kim");
                bur.executeForm(form);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    
    return 0;
}
