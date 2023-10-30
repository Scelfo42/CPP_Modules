/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:59:47 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/30 15:24:13 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

#include <iostream>
#include <fstream>
#include <sstream>

bool	inputError( int argc, char **argv, std::string& filename );
void	replaceFileContent( std::ifstream& inputFile, std::ofstream& outputFile, char **argv);

#endif