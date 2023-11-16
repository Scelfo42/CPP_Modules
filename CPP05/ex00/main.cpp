/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:43:42 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/16 14:06:08 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
    Bureaucrat  bureaucrat1("Bureaucrat1", 1);
    std::cout << bureaucrat1 << std::endl;

    Bureaucrat  bureaucrat2("Bureaucrat2", 150);
    std::cout << bureaucrat2 << std::endl;

    Bureaucrat  bureaucrat3("Bureaucrat3", 151);
    std::cout << bureaucrat3 << std::endl;
    
    Bureaucrat  bureaucrat4("Bureaucrat4", 0);
    std::cout << bureaucrat4 << std::endl;


    return 0;
}