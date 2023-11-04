/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:54:27 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 21:30:26 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static int	calcDet(int det[3][3])
{
	int	diagonal;
	int reverseDiagonal;
	int	result;

	diagonal = (det[0][0] * det[1][1] * det[2][2]) + (det[0][1] * det[1][2] * det[2][0]) + (det[0][2] * det[1][0] * det[2][1]);
	reverseDiagonal = (det[0][2] * det[1][1] * det[2][0]) + (det[0][1] * det[1][0] * det[2][2]) + (det[0][0] * det[1][2] * det[2][1]);
	result = diagonal - reverseDiagonal;
	return (result >= 0) ? result : -result;
}

static int subArea( Point const vert1, Point const vert2, Point const vert3 )
{
	int	det[3][3] = { { vert1.getX(), vert1.getY(), 1 },
					{ vert2.getX(), vert2.getY(), 1 },
					{ vert3.getX(), vert3.getY(), 1 } };
	return (calcDet(det) / 2);
}

static bool	checkEdge( Point const a, Point const b, Point const c, Point const point )
{
	if ((a.getX() == point.getX() && a.getY() == point.getY()) ||
		(b.getX() == point.getX() && b.getY() == point.getY()) ||
		(c.getX() == point.getX() && c.getY() == point.getY()))
		return true;
	return false;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	static int	i = 0;

	i++;
	if (checkEdge(a, b, c, point))
		return false;
	int	masterTriangle = subArea(a, b, c);
	std::cout << "masterTriangle: " << masterTriangle << std::endl;
	int	subTriangles[3] = { subArea(a, b, point), subArea(b, c, point), subArea(a, c, point) };
	std::cout << "subTriangles [" << i << "]: " << subTriangles[0] << " " << subTriangles[1] << " " << subTriangles[2] << std::endl;
	int sumSubTriangles = subTriangles[0] + subTriangles[1] + subTriangles[2];
	std::cout << "sumSubTriangles: " << sumSubTriangles << std::endl;
	return (masterTriangle == sumSubTriangles);
}
