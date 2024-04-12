/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:56:34 by fbriglia          #+#    #+#             */
/*   Updated: 2024/04/11 16:43:01 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    megaphone(int argc, char **argv)
{
    for (int i = 1; i < argc; i += 1)
    {
        for (int j = 0; j < (int)((std::string)argv[i]).length(); j += 1)
        {
            std::cout << (char)toupper(argv[i][j]);
        }
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
        megaphone(argc, argv);
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}