/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:05:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/17 12:29:02 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
    Bureaucrat  doddo("Doddo", 150);
    Bureaucrat  doddo2("Doddo2", 140);
    Bureaucrat  onlyFirst("OnlyFirst", 130);
    Bureaucrat  firstTwo("firstTwo", 40);
    Bureaucrat  all("All", 1);

    ShrubberyCreationForm Shrubbery("Shrubbery"); //145, 137
    RobotomyRequestForm Robotomy("Robotomy"); //72, 45
    PresidentialPardonForm President("President"); //25, 5
    std::cout << std::endl;

    doddo.signForm(Shrubbery);
    doddo.executeForm(Shrubbery);
    std::cout << std::endl;

    doddo2.signForm(Shrubbery);
    doddo2.executeForm(Shrubbery);
    std::cout << std::endl;

    onlyFirst.signForm(Shrubbery);
    onlyFirst.executeForm(Shrubbery);
    onlyFirst.signForm(Robotomy);
    std::cout << std::endl;

    firstTwo.signForm(Robotomy);
    firstTwo.executeForm(Robotomy);
    firstTwo.signForm(President);
    std::cout << std::endl;

    all.signForm(President);
    all.executeForm(President);
    std::cout << std::endl;

    return 0;
}