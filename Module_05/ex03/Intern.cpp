/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:34:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/07 14:23:24 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Intern default constructor called" << "\033[0m" << std::endl;
#endif
}

Intern::Intern(const Intern &cp)
{
(void)cp;
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Intern copy constructor called" << "\033[0m" << std::endl;
#endif 
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
    static struct { AForm* (*f)(const std::string&); std::string name; } array[3] = {
        {ShrubberyCreationForm::create, "shrubbery creation"},
        {RobotomyRequestForm::create, "robotomy request"},
        {PresidentialPardonForm::create, "presidential pardon"}
    };

    for (int i = 0; i < int(sizeof(array) / sizeof(array[0])); i++)
    {
        if (array[i].name == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return array[i].f(target);
        }
    }
    std::cout << name << ": unknown form name" << std::endl;
    return NULL;
}

Intern::~Intern()
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Intern destructor called" << "\033[0m" << std::endl;
#endif
}

Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Intern copy assignement operator called" << "\033[0m" << std::endl;
#endif
    return *this;
}
