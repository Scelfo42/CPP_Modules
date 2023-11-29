/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:00:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/29 16:53:55 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main( void )
{
	Data		data;
	Data		*serializedData;
	uintptr_t	serializedPtr;

	data.character = 'a';
	data.string = "Hello";
	data.number = 42;
	data.floatNumber = 42.42f;
	data.doubleNumber = 42.42;

	std::cout << "Data: " << data.character << ", " << data.string << ", " << data.number << ", " << data.floatNumber << ", " << data.doubleNumber << std::endl;
	std::cout << std::endl << "Serializing data..." << std::endl;

	serializedPtr = Serializer::serialize(&data);
	std::cout << "SerializedPtr: " << serializedPtr << std::endl;
	std::cout << std::endl << "Deserializing data into another serializedData..." << std::endl;
	
	serializedData = Serializer::deserialize(serializedPtr);
	std::cout << "Data: " << data.character << ", " << data.string << ", " << data.number << ", " << data.floatNumber << ", " << data.doubleNumber << std::endl << std::endl;
	std::cout << "serializedData: " << data.character << ", " << data.string << ", " << data.number << ", " << data.floatNumber << ", " << data.doubleNumber << std::endl;

	return 0;
}