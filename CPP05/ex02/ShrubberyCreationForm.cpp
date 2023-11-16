/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:09:38 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/16 18:26:01 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm() { std::cout << "ShrubberyCreationForm default constructor called" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137) { std::cout << "ShrubberyCreationForm parametric constructor called" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& sourceClass ) : AForm(sourceClass)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = sourceClass;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) { std::cout << "ShrubberyCreationForm destructor called" << std::endl; }

ShrubberyCreationForm&  ShrubberyCreationForm::operator=( const ShrubberyCreationForm& sourceClass )
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &sourceClass)
        this->target = sourceClass.target;
    return *this;
}
