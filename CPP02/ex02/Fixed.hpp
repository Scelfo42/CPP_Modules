/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:11:32 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/03 14:37:36 by cscelfo          ###   ########.fr       */
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

		bool	operator>( Fixed const & otherInstance ) const;
		bool	operator<( Fixed const & otherInstance ) const;
		bool	operator>=( Fixed const & otherInstance ) const;
		bool	operator<=( Fixed const & otherInstance ) const;
		bool	operator==( Fixed const & otherInstance ) const;
		bool	operator!=( Fixed const & otherInstance ) const;

		Fixed	operator+( Fixed const & otherInstance ) const;
		Fixed	operator-( Fixed const & otherInstance ) const;
		Fixed	operator*( Fixed const & otherInstance ) const;
		Fixed	operator/( Fixed const & otherInstance ) const;

		Fixed	operator++( int );
		Fixed	operator--( int );
		Fixed&	operator++( void );
		Fixed&	operator--( void );

		static Fixed&			min( Fixed& firstInstance, Fixed& secondInstance );
		static Fixed const &	min( Fixed const & firstInstance, Fixed const & secondInstance );
		static Fixed&			max( Fixed& firstInstance, Fixed& secondInstance );
		static Fixed const &	max( Fixed const & firstInstance, Fixed const & secondInstance );
};

std::ostream&	operator<<( std::ostream & stdOutStream, Fixed const & instance);