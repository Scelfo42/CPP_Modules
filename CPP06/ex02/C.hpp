/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:19:13 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/30 10:58:20 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef C_HPP
# define C_HPP

# include "B.hpp"

class C : public Base
{
	public:
		C( void );
		virtual ~C( void );
};

#endif
