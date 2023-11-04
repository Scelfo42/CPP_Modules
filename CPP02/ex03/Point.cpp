/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:55:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 20:44:13 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//========= CONSTRUCTOR =========//

Point::Point( void ) : _x(0), _y(0) { }

Point::Point( const float x, const float y ) : _x(x), _y(y) { }

Point::Point( const Point& sourceClass ) { *this = sourceClass; }

//========= DESTRUCTOR =========//

Point::~Point( void ) { }

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

Point&	Point::operator=( const Point& sourceClass )
{
	if (this != &sourceClass)
	{
		const_cast<Fixed&>(_x) = sourceClass.getX();
		const_cast<Fixed&>(_y) = sourceClass.getY();
	}
	return *this;
}

//========= GETTER FUNCTION =========//

float	Point::getX( void ) const { return _x.toFloat(); }

float	Point::getY( void ) const { return _y.toFloat(); }
