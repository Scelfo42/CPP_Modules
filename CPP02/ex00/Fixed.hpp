/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:11:10 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/02 16:11:56 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int					_fixedNumber;
		static const int	_fractionalBits = 8;
	public:
		Fixed( void );
		Fixed( Fixed const & newInstance );
		~Fixed( void );

		Fixed&	operator=( Fixed const & modifiedInstance );
	
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};