/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:19:36 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/30 15:32:58 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

int	main( int argc, char **argv )
{
	std::ifstream		inputFile;
	std::ofstream		outputFile;
	std::string			filename;

	if (inputError(argc, argv, filename))
		return 1;

	inputFile.open(argv[1]);
	outputFile.open(filename.c_str(), std::ofstream::trunc);

	replaceFileContent(inputFile, outputFile, argv);

	inputFile.close();
	outputFile.close();
	return 0;
}
