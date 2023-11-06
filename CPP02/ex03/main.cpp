/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:11:07 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/06 11:17:30 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Please note that an edge point is considered outside the triangle (see the subject)

int main ()
{
    Point   in(3, 1);
    Point   out(10, 10);
    Point   vertex(2, 6);
	Point	edge(2, 0);
    
    bool    insidePoint = bsp( Point(0, 0), Point(2, 6), Point(4, 0), in);
    bool    outsidePoint = bsp( Point(0, 0), Point(2, 6), Point(4, 0), out);
    bool    vertexPoint = bsp( Point(0, 0), Point(2, 6), Point(4, 0), vertex);
	bool	edgePoint = bsp( Point(0, 0), Point(2, 6), Point(4, 0), edge);

    std::cout << std::endl;
    std::cout << "Point(3, 1) is " << (insidePoint ? "inside" : "outside") << " the triangle" << std::endl;
    std::cout << "Point(10, 10) is " << (outsidePoint ? "inside" : "outside") << " the triangle" << std::endl;
    std::cout << "Point(2, 6) is " << (vertexPoint ? "inside" : "outside") << " the triangle" << std::endl;
    std::cout << "Point(2, 0) is " << (edgePoint ? "inside" : "outside") << " the triangle" << std::endl;
    std::cout << std::endl;

    return 0;
}
