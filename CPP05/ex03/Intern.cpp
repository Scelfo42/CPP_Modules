/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:12:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/17 14:57:36 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) { std::cout << "Intern default constructor called" << std::endl; }

Intern::Intern( const Intern& sourceClass )
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = sourceClass;
}

Intern::~Intern( void ) { std::cout << "Intern destructor called" << std::endl; }

Intern& Intern::operator=( const Intern& sourceClass )
{
    std::cout << "Intern assigment operator called" << std::endl;
    if (this != &sourceClass)
        ;
    return *this;
}

static size_t checkFormName( std::string formName, std::string availableNames[3] )
{
    for (size_t i = 0; i < availableNames->size(); i++)
    {
        if (!formName.compare(availableNames[i]))
            return i;
    }
    return 3;
}

AForm*  Intern::makeForm( std::string formName, std::string formTarget )
{
    std::string availableNames[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    int         index = checkFormName(formName, availableNames);
    AForm*      form;
    
    if (index >= 0 && index < 3)
    {
        try
        {
            switch (index)
            {
                case 0:
                    form = new ShrubberyCreationForm(formTarget);
                    break ;
                case 1:
                    form = new RobotomyRequestForm(formTarget);
                    break ;
                case 2:
                    form = new PresidentialPardonForm(formTarget);
                    break ;
            }
            std::cout << "Intern creates " << availableNames[index] << " form" << std::endl;
            return form;
        }
        catch (std::bad_alloc& error)
        {
            std::cerr << error.what() << std::endl;
        }
    }
    std::cout << formName << " couldn't be created!" << std::endl;
    return NULL;
}
