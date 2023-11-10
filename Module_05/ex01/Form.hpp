/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:03:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/05 21:31:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

#ifdef BUREAUCRAT_HPP
class Bureaucrat;
#endif

#include "Bureaucrat.hpp"

class Form
{
    public:
        class GradeTooHighException: public std::exception
        {
            virtual const char* what() const throw();
        };
        
        class GradeTooLowException: public std::exception
        {
            virtual const char* what() const throw();
        };

        Form();
        Form(const Form& cp);
        Form(const std::string& name, int required_grade_sign, int required_grade_exec);
        
        const std::string& getName() const;
        bool getIsSigned() const;
        int getRequiredGradeSign() const;
        int getRequiredGradeExec() const;

        void beSigned(const Bureaucrat& bur);

        ~Form();
    private:
        const std::string name;
        bool is_signed;
        const int required_grade_sign;
        const int required_grade_exec;

    public:
        Form& operator=(const Form& rhs);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP