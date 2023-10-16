/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:36:14 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/16 16:52:37 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		_contacts[8];
		int			_countContacts;
	public:
		PhoneBook( void );
		~PhoneBook( void );

		void		addContact( bool* ctrlD );
		void		searchContact( bool* ctrlD );
};

#endif
