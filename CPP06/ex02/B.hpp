/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:18:29 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/30 10:58:24 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef B_HPP
# define B_HPP

# include "A.hpp"

class B : public Base
{
	public:
		B( void );
		virtual ~B( void );
};

#endif
