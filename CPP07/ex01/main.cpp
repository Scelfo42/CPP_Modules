/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:44:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/01 16:03:08 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main( void )
{
	int				tab[] = { 0, 1, 2, 3, 4 };
	unsigned int	tab2[] = { 5, 6, 7, 8, 9 };
	Awesome			tab3[5];

	std::cout << "-int array:" << std::endl;
	iter( tab, 5, print<int> );
	std::cout << std::endl;
	std::cout << "-const int:" << std::endl;
	iter( tab, 5, print<const int> );
	std::cout << std::endl;
	std::cout << "-unsigned int array:" << std::endl;
	iter( tab2, 5, print<unsigned int> );
	std::cout << std::endl;
	std::cout << "-const unsigned int:" << std::endl;
	iter( tab2, 5, print<const unsigned int> );
	std::cout << std::endl;
	std::cout << "-Awesome array:" << std::endl;
	iter( tab3, 5, print<Awesome> );
	std::cout << std::endl;
	std::cout << "-const Awesome:" << std::endl;
	iter( tab3, 5, print<const Awesome> );

  return 0;
}
