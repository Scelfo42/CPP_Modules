/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:14:24 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/16 17:58:24 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

static bool checkGrade( int grade1, int grade2 )
{
    if (grade1 < 1 || grade2 < 1)
    {
        throw Bureaucrat::GradeTooHighException();
        return true;
    }
    else if (grade2 > 150 || grade2 > 150)
    {
        throw Bureaucrat::GradeTooLowException();
        return true;
    }
    return false;
}

AForm::AForm( void ) : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm( std::string name, int gradeToSign, int gradeToExecute ) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "AForm parametric constructor called" << std::endl;
    try
    {
        checkGrade(this->_gradeToSign, this->_gradeToExecute);
    }
    catch(const std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
}

AForm::AForm( const AForm& sourceClass ) : _name(sourceClass._name), _gradeToSign(sourceClass._gradeToSign), _gradeToExecute(sourceClass._gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
    try
    {
        checkGrade(this->_gradeToSign, this->_gradeToExecute);
    }
    catch(const std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
    *this = sourceClass;
}

AForm::~AForm( void ) { std::cout << "AForm destructor called" << std::endl; }

AForm&   AForm::operator=( const AForm& sourceClass )
{
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &sourceClass)
        this->_signed = sourceClass._signed;
    return *this;
}

std::string AForm::getName( void ) const { return this->_name; }

bool    AForm::getSigned( void ) const { return this->_signed; }

int AForm::getGradeToSign( void ) const { return this->_gradeToSign; }

int AForm::getGradeToExecute( void ) const { return this->_gradeToExecute; }

void    AForm::beSigned( const Bureaucrat& instance )
{
    try
    {
        if (!checkGrade(this->_gradeToSign, 1))
            if (instance.getGrade() <= this->_gradeToSign)
                this->_signed = true;
    }
    catch(const std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
}

std::ostream&   operator<<( std::ostream& stdOut, const AForm& instance )
{
    stdOut << "Name: " << instance.getName() << std::endl;
    stdOut << "signed: " << instance.getSigned() << std::endl;
    stdOut << "gradeToSign: " << instance.getGradeToSign() << std::endl;
    stdOut << "gradeToExecute: " << instance.getGradeToExecute() << std::endl;
    return stdOut;
}
