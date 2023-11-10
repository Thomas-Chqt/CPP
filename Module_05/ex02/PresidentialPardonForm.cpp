/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:01:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/06 14:39:24 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <fstream>

#define SIGN_REQUIRED 25
#define EXEC_REQUIRED 5

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("presidential pardon", SIGN_REQUIRED, EXEC_REQUIRED), target("Unkown target")
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "PresidentialPardonForm default constructor called" << "\033[0m" << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cp)
    : AForm(cp), target(cp.target)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "PresidentialPardonForm copy constructor called" << "\033[0m" << std::endl;
#endif  
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("presidential pardon", SIGN_REQUIRED, EXEC_REQUIRED), target(target)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "PresidentialPardonForm copy constructor called" << "\033[0m" << std::endl;
#endif 
}

void PresidentialPardonForm::execute() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "PresidentialPardonForm destructor called" << "\033[0m" << std::endl;
#endif
}