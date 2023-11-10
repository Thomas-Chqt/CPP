/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:52:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/07 14:40:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <fstream>

#define SIGN_REQUIRED 72
#define EXEC_REQUIRED 45

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("robotomy request", SIGN_REQUIRED, EXEC_REQUIRED), target("Unkown target")
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "RobotomyRequestForm default constructor called" << "\033[0m" << std::endl;
#endif
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cp)
    : AForm(cp), target(cp.target)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "RobotomyRequestForm copy constructor called" << "\033[0m" << std::endl;
#endif  
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("robotomy request", SIGN_REQUIRED, EXEC_REQUIRED), target(target)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "RobotomyRequestForm copy constructor called" << "\033[0m" << std::endl;
#endif 
    std::srand(std::time(NULL));
}

AForm *RobotomyRequestForm::create(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

void RobotomyRequestForm::execute() const
{
    int nbr = std::rand();

    std::cout << "*** drilling noises ***" << std::endl;
    if (nbr % 2 == 0)
        std::cout << this->target << " has been robotomized" << std::endl;
    else
        std::cout << this->target << " robotomisation failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "RobotomyRequestForm destructor called" << "\033[0m" << std::endl;
#endif
}