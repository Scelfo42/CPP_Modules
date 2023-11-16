/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:10:33 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/16 18:29:58 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm() { std::cout << "PresidentialPardonForm default constructor called" << std::endl; }

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5) { std::cout << "PresidentialPardonForm parametric constructor called" << std::endl; }

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& sourceClass ) : AForm(sourceClass)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = sourceClass;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) { std::cout << "PresidentialPardonForm destructor called" << std::endl; }

PresidentialPardonForm&  PresidentialPardonForm::operator=( const PresidentialPardonForm& sourceClass )
{
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &sourceClass)
        this->target = sourceClass.target;
    return *this;
}
