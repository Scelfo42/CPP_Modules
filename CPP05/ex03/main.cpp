/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:05:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/17 14:58:05 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main( void )
{
    Intern  someRandomIntern;
    AForm*  rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    delete rrf;

    return 0;
}