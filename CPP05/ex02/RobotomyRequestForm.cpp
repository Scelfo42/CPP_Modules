/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:10:16 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/17 12:22:37 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm() { std::cout << "RobotomyRequestForm default constructor called" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm(target, 72, 45), _target(target) { std::cout << "RobotomyRequestForm parametric constructor called" << std::endl; }

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
        this->_target = sourceClass._target;
    return *this;
}

void    RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
    for (int i = 0; i < 5; i++)
        std::cout << "Drrrrrrrrrr" << std::endl;
    std::cout << this->_target << " ";
    if (rand() % 2 == 0)
        std::cout << "has been robotomized successfully" << std::endl;
    else
        std::cout << "hasn't been robotomized, lucky you" << std::endl;
    (void)executor;
}
