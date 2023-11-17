/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:10:17 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/17 10:10:46 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( std::string );
        RobotomyRequestForm( const RobotomyRequestForm& );
        ~RobotomyRequestForm( void );

        RobotomyRequestForm&  operator=( const RobotomyRequestForm& );

        virtual void    execute( const Bureaucrat& executor ) const;
};

#endif
