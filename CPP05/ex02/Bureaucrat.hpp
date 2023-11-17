/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:44:17 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/17 11:57:45 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string       _name;
        int                     _grade;
    public:
        Bureaucrat( void );
        Bureaucrat( std::string name, int grade );
        Bureaucrat( const Bureaucrat& sourceClass );
        ~Bureaucrat( void );

        Bureaucrat& operator=( const Bureaucrat& sourceClass );

        std::string getName( void ) const;
        int         getGrade( void ) const;

        void        incrementGrade( int incrementValue );
        void        decrementGrade( int decrementValue );

        void        signForm( AForm& );
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Bureaucrat: grade too low";
                }
        };
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Bureaucrat: grade too high";
                }
        };

        void    executeForm( const AForm& form ) const;
};

std::ostream& operator<<( std::ostream& stdOutStream, const Bureaucrat& instance);

#endif
