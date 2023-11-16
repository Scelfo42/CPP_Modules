/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:43:42 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/16 18:04:19 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    Bureaucrat  bob("Bob", 151);
    Form        job("Cybersecurity Analyst", -3, 30);
    Form        contract(job);
    
    job.beSigned(bob);
    std::cout << std::endl;
    std::cout << job;
    std::cout << std::endl;

    bob.incrementGrade(140);
    
    std::cout << bob;

    bob.signForm(contract);
    return 0;
}