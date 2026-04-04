/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:55:19 by fadzejli          #+#    #+#             */
/*   Updated: 2026/02/23 13:55:20 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void    replaceFile(std::ifstream& fd, std::ofstream& outputFd, const std::string& s1, const std::string& s2)
{
    std::string line;
    std::string result;
    size_t     i = 0;

    while (std::getline(fd, line))
    {
        result = line;
        i = 0;
        while ((i = result.find(s1, i)) != std::string::npos)
        {
            result.erase(i, s1.length());
            result.insert(i, s2);
            i += s2.length();
        }
        outputFd << result << std::endl;
    }
}

int main(int ac, char **av)
{
    std::string fileName;
    std::string s1;
    std::string s2;

    if (ac != 4)
    {
        std::cerr << "Check yout inputs" << std::endl;
        return (1);
    }
    fileName = av[1];
    s1 = av[2];
    s2 = av[3];
    if (fileName.empty() || s1.empty())
    {
        std::cerr << "File and <s1> can not be empty" << std::endl;
        return (1);
    }
    std::ifstream fd(fileName.c_str());
    if (!fd.is_open())
    {
        std::cerr << "Error: cannot open file " << fileName << std::endl;
        return (1);
    }
    std::ofstream newFd((fileName + ".replace").c_str());
    if (!newFd.is_open())
    {
        std::cerr << "Error: cannot open file " << fileName + ".replace" << std::endl;
        return (1);
    }
    replaceFile(fd, newFd, s1, s2);
    fd.close();
    newFd.close();
    return (0);
}