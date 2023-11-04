/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:54:39 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 19:25:45 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point( void );
		Point( const float x, const float y );
		Point( const Point& sourceClass );
		~Point( void );

		Point&	operator=( const Point& sourceClass );
		
		float	getX( void ) const;
		float	getY( void ) const;
};
		
		bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif