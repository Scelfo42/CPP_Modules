/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:44:04 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/17 12:18:50 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//========= GRADE CHECKER =========//

static bool checkGrade( int grade )
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
        return true;
    }
    else if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
        return true;
    }
    return false;
}

//========= CONSTRUCTOR =========//

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150) { std::cout << "Bureaucrat default constructor called" << std::endl; }

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
    std::cout << "Bureaucrat parametric constructor called" << std::endl;
    try
    {
        if (!checkGrade(grade))
            this->_grade = grade;
    }
    catch(std::exception& error)
    {
        std::cerr << error.what() << std::endl;
        this->_grade = 150;
        std::cout << this->_name << "'s grade was set to " << this->_grade << " because it was out of bounds." << std::endl;
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

void    Bureaucrat::incrementGrade( int incrementValue )
{
    try
    {
        if (!checkGrade(_grade - incrementValue))
            this->_grade -= incrementValue;
    }
    catch(std::exception& error)
    {
        std::cerr << error.what() << std::endl;
        std::cout << this->_name << "'s grade wasn't changed" << std::endl;
    }
    
}

void    Bureaucrat::decrementGrade( int decrementValue )
{
    try
    {
        if (!checkGrade(_grade + decrementValue))
            this->_grade += decrementValue;
    }
    catch(std::exception& error)
    {
        std::cerr << error.what() << std::endl;
        std::cout << this->_name << "'s grade wasn't changed" << std::endl;
    }
}

std::ostream&   operator<<( std::ostream& stdOutStream, const Bureaucrat& instance)
{
    stdOutStream << instance.getName() << ", bureaucrat grade " << instance.getGrade() << "." << std::endl;
    return stdOutStream;
}

void    Bureaucrat::signForm( AForm& form )
{
    form.beSigned(*this);
    if (form.getSigned())
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    else
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because ";
        if (this->_grade > form.getGradeToSign())
            std::cout << this->_name << "'s grade: " << this->_grade << ", is too low to sign " << form.getName() << "'s gradeToSign: " << form.getGradeToSign() << std::endl;
        else
            std::cout << form.getName() << "'s grade: " << form.getGradeToSign() << " is invalid" << std::endl;
    }

    
}

void    Bureaucrat::executeForm( const AForm& form ) const
{
    if (form.checkExecute(*this))
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    else
    {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because ";
        if (!form.getSigned())
            std::cout << form.getName() << " isn't signed" << std::endl;
        else
            std::cout << this->_name << "'s grade: " << this->_grade << ", is too low to execute " << form.getName() << "'s gradeToExecute: " << form.getGradeToExecute() << std::endl;
    }
    
}
