/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:09:55 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/17 10:12:08 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( std::string );
        ShrubberyCreationForm( const ShrubberyCreationForm& );
        ~ShrubberyCreationForm( void );

        ShrubberyCreationForm&  operator=( const ShrubberyCreationForm& );

        virtual void    execute( const Bureaucrat& ) const;
};

#endif
