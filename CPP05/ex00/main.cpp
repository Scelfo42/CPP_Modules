/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:43:42 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/16 16:25:50 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
    Bureaucrat  bob1("bob", 2);
    std::cout << bob1 << std::endl;

    bob1.incrementGrade(1);
    std::cout << bob1 << std::endl;

    bob1.incrementGrade(1);
    std::cout << bob1 << std::endl;

    bob1.decrementGrade(150);
    std::cout << bob1 << std::endl;

    bob1.decrementGrade(149);
    std::cout << bob1 << std::endl;

    return 0;
}