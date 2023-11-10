/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:10:01 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/07 14:26:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grad too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grad too low";
}

Form::Form()
    : name("No name"), is_signed(false),
      required_grade_sign(150), required_grade_exec(150)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Form default constructor called" << "\033[0m" << std::endl;
#endif
}

Form::Form(const Form &cp)
    : name(cp.name), is_signed(cp.is_signed),
      required_grade_sign(cp.required_grade_sign),
      required_grade_exec(cp.required_grade_exec)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Form copy constructor called" << "\033[0m" << std::endl;
#endif  
}

Form::Form(const std::string &name, int required_grade_sign, int required_grade_exec)
    : name(name), is_signed(false),
      required_grade_sign(required_grade_sign),
      required_grade_exec(required_grade_exec)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Form constructor called" << "\033[0m" << std::endl;
#endif

    if (required_grade_sign < 1 || required_grade_exec < 1)
        throw Form::GradeTooHighException();
    if (required_grade_sign > 150 || required_grade_exec > 150)
        throw Form::GradeTooLowException();
}

const std::string &Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->is_signed;
}

int Form::getRequiredGradeSign() const
{
    return this->required_grade_sign;
}

int Form::getRequiredGradeExec() const
{
    return this->required_grade_exec;
}

void Form::beSigned(const Bureaucrat &bur)
{
    if (bur.getGrade() > this->required_grade_sign)
        throw Form::GradeTooLowException();
    this->is_signed = true;    
}

Form::~Form()
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Form destructor called" << "\033[0m" << std::endl;
#endif
}

Form& Form::operator=(const Form& rhs)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Form copy assignement operator called" << "\033[0m" << std::endl;
#endif

    this->is_signed = rhs.is_signed;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "form name : "                 << form.getName()                                 << std::endl
       << "grade required to sign : "    << form.getRequiredGradeSign()                    << std::endl
       << "grade required to execute : " << form.getRequiredGradeExec()                    << std::endl
       << "status : "                    << (form.getIsSigned() ? "Signed" : "Not signed");
    
    return os;   
}