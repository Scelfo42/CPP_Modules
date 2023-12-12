/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:39:27 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/12 15:48:09 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind( T& container, const int& value )
{
	typename T::iterator itEnd = container.end();
    typename T::iterator findValue = std::find(container.begin(), itEnd, value);

	if (findValue == itEnd)
        throw ValueNotFoundException();
    return findValue;
}