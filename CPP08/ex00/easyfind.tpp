/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:39:27 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/13 14:49:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

template <typename T>
typename T::const_iterator	easyfind( const T& container, const int& value )
{
	typename T::const_iterator	itEnd = container.end();

	for (typename T::const_iterator it = container.begin(); it != itEnd; ++it)
	{
		if (*it == value)
			return it;
	}
	throw ValueNotFoundException();
}
