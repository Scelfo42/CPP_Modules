/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:44:04 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/16 14:05:06 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//========= CONSTRUCTOR =========//

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150) { std::cout << "Bureaucrat default constructor called" << std::endl; }

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
    std::cout << "Bureaucrat parametric constructor called" << std::endl;
    try
    {
        this->_grade = grade;
        if (this->_grade < 1)
            throw Bureaucrat::GradeTooLowException();
        else if (this->_grade > 150)
            throw Bureaucrat::GradeTooHighException();
    }
    catch(std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
    
}

Bureaucrat::Bureaucrat( const Bureaucrat& sourceClass ) : _name(sourceClass.getName())
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = sourceClass;
}

//========= DESTRUCTOR =========//

Bureaucrat::~Bureaucrat( void ) { std::cout << "Bureaucrat destructor called" << std::endl; }

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& sourceClass )
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &sourceClass)
        this->_grade = sourceClass.getGrade();
    return *this;
}

//========= GETTER =========//

std::string Bureaucrat::getName( void ) const { return this->_name; }

int Bureaucrat::getGrade( void ) const { return this->_grade; }

void    Bureaucrat::incrementGrade( void )
{
    try
    {
        this->_grade -= 1;
        if (this->_grade < 1)
            throw Bureaucrat::GradeTooLowException();
    }
    catch(std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
    
}

void    Bureaucrat::decrementGrade( void )
{
    try
    {
        
        this->_grade += 1;
        if (this->_grade > 150)
            throw Bureaucrat::GradeTooHighException();
    }
    catch(std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
}

std::ostream&   operator<<( std::ostream& stdOutStream, const Bureaucrat& instance)
{
    stdOutStream << instance.getName() << ", bureaucrat grade " << instance.getGrade() << "." << std::endl;
    return stdOutStream;
}
