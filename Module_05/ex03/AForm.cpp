/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:17:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/07 14:30:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grad too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grad too low";
}

AForm::AForm()
    : name("No name"), is_signed(false),
      required_grade_sign(150), required_grade_exec(150)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "AForm default constructor called" << "\033[0m" << std::endl;
#endif
}

AForm::AForm(const AForm &cp)
    : name(cp.name), is_signed(cp.is_signed),
      required_grade_sign(cp.required_grade_sign),
      required_grade_exec(cp.required_grade_exec)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "AForm copy constructor called" << "\033[0m" << std::endl;
#endif  
}

AForm::AForm(const std::string &name, int required_grade_sign, int required_grade_exec)
    : name(name), is_signed(false),
      required_grade_sign(required_grade_sign),
      required_grade_exec(required_grade_exec)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "AForm constructor called" << "\033[0m" << std::endl;
#endif

    if (required_grade_sign < 1 || required_grade_exec < 1)
        throw AForm::GradeTooHighException();
    if (required_grade_sign > 150 || required_grade_exec > 150)
        throw AForm::GradeTooLowException();
}

const std::string &AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->is_signed;
}

int AForm::getRequiredGradeSign() const
{
    return this->required_grade_sign;
}

int AForm::getRequiredGradeExec() const
{
    return this->required_grade_exec;
}

void AForm::beSigned(const Bureaucrat &bur)
{
    if (bur.getGrade() > this->required_grade_sign)
        throw AForm::GradeTooLowException();
    this->is_signed = true;    
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > required_grade_exec)
        throw AForm::GradeTooLowException();
    this->execute();
}

AForm::~AForm()
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "AForm destructor called" << "\033[0m" << std::endl;
#endif
}

AForm& AForm::operator=(const AForm& rhs)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "AForm copy assignement operator called" << "\033[0m" << std::endl;
#endif

    this->is_signed = rhs.is_signed;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "form name : "                 << form.getName()                                 << std::endl
       << "grade required to sign : "    << form.getRequiredGradeSign()                    << std::endl
       << "grade required to execute : " << form.getRequiredGradeExec()                    << std::endl
       << "status : "                    << (form.getIsSigned() ? "Signed" : "Not signed");
    
    return os;   
}