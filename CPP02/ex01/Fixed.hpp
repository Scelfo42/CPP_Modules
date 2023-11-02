/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:05:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/02 16:23:16 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedNumber;
		static const int	_fractionalBits = 8;
	public:
		Fixed( void );
		Fixed( Fixed const & newInstance );
		Fixed( int const intNumber );
		Fixed( float const floatNumber );
		~Fixed( void );

		Fixed&	operator=( Fixed const & modifiedInstance );
	
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream&	operator<<( std::ostream & stdOutStream, Fixed const & instance);