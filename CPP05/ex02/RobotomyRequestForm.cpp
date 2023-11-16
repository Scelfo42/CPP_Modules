/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:10:16 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/16 18:29:47 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm() { std::cout << "RobotomyRequestForm default constructor called" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45) { std::cout << "RobotomyRequestForm parametric constructor called" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& sourceClass ) : AForm(sourceClass)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = sourceClass;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) { std::cout << "RobotomyRequestForm destructor called" << std::endl; }

RobotomyRequestForm&  RobotomyRequestForm::operator=( const RobotomyRequestForm& sourceClass )
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &sourceClass)
        this->target = sourceClass.target;
    return *this;
}
