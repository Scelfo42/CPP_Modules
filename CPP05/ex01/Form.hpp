/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:14:37 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/16 17:43:10 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        Form( void );
        Form( std::string, int, int);
        Form( const Form& );
        ~Form( void );

        Form&      operator=( const Form& );

        std::string getName( void ) const;
        bool        getSigned( void ) const;
        int         getGradeToSign( void ) const;
        int         getGradeToExecute( void ) const;

        void        beSigned( const Bureaucrat& );

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Form: Too low grade";
                }
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Form: Too high grade";
                }
        };
};

std::ostream&   operator<<( std::ostream&, const Form& );

#endif