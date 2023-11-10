/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:37:48 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/06 13:12:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

#define SIGN_REQUIRED 145
#define EXEC_REQUIRED 137

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("shrubbery creation", SIGN_REQUIRED, EXEC_REQUIRED), target("Unkown target")
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "ShrubberyCreationForm default constructor called" << "\033[0m" << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cp) : AForm(cp), target(cp.target)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "ShrubberyCreationForm copy constructor called" << "\033[0m" << std::endl;
#endif  
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("shrubbery creation", SIGN_REQUIRED, EXEC_REQUIRED), target(target)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "ShrubberyCreationForm copy constructor called" << "\033[0m" << std::endl;
#endif 
}

void ShrubberyCreationForm::execute() const
{
   std::ofstream file(target + "_shrubbery");

   file <<
"                  v .   ._, |_  .,\n"
"           `-._\\/  .  \\ /    |/_\n"
"               \\  _\\, y | \\//\n"
"         _\\_.___\\, \\/ -.\\||\n"
"           `7-,--.`._||  / / ,\n"
"           /'     `-. `./ / |/_.'\n"
"                     |    |//\n"
"                     |_    /\n"
"                     |-   |\n"
"                     |   =|\n"
"                     |    |\n"
"--------------------/ ,  . \\--------._\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "ShrubberyCreationForm destructor called" << "\033[0m" << std::endl;
#endif
}
