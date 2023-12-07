/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:39:27 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/07 15:20:36 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind( T& container, const int& value )
{
	typename T::iterator it_end = container.end();

	for (typename T::iterator it = container.begin(); it != it_end; it++)
	{
		if (*it == value)
			return it;
	}
	throw ValueNotFoundException();
}