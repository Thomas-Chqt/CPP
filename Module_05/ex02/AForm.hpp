/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:47:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/06 13:41:55 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

#ifdef BUREAUCRAT_HPP
class Bureaucrat;
#endif

#include "Bureaucrat.hpp"

class AForm
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

        AForm();
        AForm(const AForm& cp);
        AForm(const std::string& name, int required_grade_sign, int required_grade_exec);
        
        const std::string& getName() const;
        bool getIsSigned() const;
        int getRequiredGradeSign() const;
        int getRequiredGradeExec() const;

        void beSigned(const Bureaucrat& bur);
        void execute(const Bureaucrat& executor) const;

        virtual ~AForm();
    private:
        virtual void execute() const = 0;

        const std::string name;
        bool is_signed;
        const int required_grade_sign;
        const int required_grade_exec;

    public:
        AForm& operator=(const AForm& rhs);
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // AFORM_HPP