/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:28 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/22 14:11:30 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int argc, char** argv )
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
}