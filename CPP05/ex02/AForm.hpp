/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:14:37 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/17 12:13:45 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AFORM_HPP
# define AFORM_HPP

#include <exception>
#include <iostream>
#include <cstdlib>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        AForm( void );
        AForm( std::string, int, int);
        AForm( const AForm& );
        ~AForm( void );

        AForm&      operator=( const AForm& );

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
                    return "Invalid Form: grade too low";
                }
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Invalid Form: grade too high";
                }
        };

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Form: not signed";
                }
        };

        virtual void    execute( const Bureaucrat& ) const = 0;
        bool            checkExecute( const Bureaucrat& ) const;
};

std::ostream&   operator<<( std::ostream&, const AForm& );

#endif