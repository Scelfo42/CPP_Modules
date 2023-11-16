/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:14:37 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/16 18:31:43 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AFORM_HPP
# define AFORM_HPP

#include <exception>
#include <iostream>

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

        virtual void    execute( const Bureaucrat& executor ) const = 0;
};

std::ostream&   operator<<( std::ostream&, const AForm& );

#endif