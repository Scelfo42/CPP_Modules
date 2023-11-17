/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:10:43 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/17 10:10:52 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( std::string );
        PresidentialPardonForm( const PresidentialPardonForm& );
        ~PresidentialPardonForm( void );

        PresidentialPardonForm&  operator=( const PresidentialPardonForm& );

        virtual void    execute( const Bureaucrat& executor ) const;
};

#endif
