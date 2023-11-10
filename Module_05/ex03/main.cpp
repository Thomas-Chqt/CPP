/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:42:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/06 13:38:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Intern.hpp"   

int main()
{
    Intern random_intern;

    std::cout << "\033[0;32m" << "Form name : 'shrubbery creation'" << "\033[0m" << std::endl;
    {
        AForm *form = random_intern.makeForm("shrubbery creation", "garden");
        delete form;
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "Form name : 'robotomy request'" << "\033[0m" << std::endl;
    {
        AForm *form = random_intern.makeForm("robotomy request", "jimmy");
        delete form;
    }
    std::cout << std::endl;
    
    std::cout << "\033[0;32m" << "Form name : 'presidential pardon'" << "\033[0m" << std::endl;
    {
        AForm *form = random_intern.makeForm("presidential pardon", "kim");
        delete form;
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "Form name : 'no such form'" << "\033[0m" << std::endl;
    {
        AForm *form = random_intern.makeForm("no such form", "lalo");
        delete form;
    }
    std::cout << std::endl;

    return 0;
}
