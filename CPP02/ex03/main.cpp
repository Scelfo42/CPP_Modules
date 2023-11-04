/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:11:07 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 19:30:39 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main ()
{
    if ( bsp( Point(0, 0), Point(2, 6), Point(4, 0), Point(3, 1) ) == true )
        std::cout << "Point is in the triangle" << std::endl;
    else
        std::cout << "Point is nope in the triangle" << std::endl;
    return 0;
}