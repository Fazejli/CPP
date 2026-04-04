/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:01:30 by fadzejli          #+#    #+#             */
/*   Updated: 2026/02/23 14:15:52 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

static int passed = 0;
static int failed = 0;

static void createFile(const std::string &path, const std::string &content)
{
    std::ofstream f(path.c_str());
    f << content;
}

static std::string readFile(const std::string &path)
{
    std::ifstream f(path.c_str());
    if (!f.is_open())
        return "__NOT_FOUND__";
    return std::string((std::istreambuf_iterator<char>(f)),
                        std::istreambuf_iterator<char>());
}

static void check(const std::string &desc, const std::string &expected, const std::string &actual)
{
    if (actual == expected)
    {
        std::cout << "[OK]  " << desc << std::endl;
        ++passed;
    }
    else
    {
        std::cout << "[KO]  " << desc << std::endl;
        std::cout << "      expected: \"" << expected << "\"" << std::endl;
        std::cout << "      got:      \"" << actual << "\"" << std::endl;
        ++failed;
    }
}

static int run(const std::string &args)
{
    return std::system(("./replace " + args + " > /dev/null 2>&1").c_str());
}

int main(void)
{
    check("No args -> error",      "1", run("") != 0 ? "1" : "0");
    check("2 args -> error",       "1", run("file.txt hello") != 0 ? "1" : "0");
    check("Missing file -> error", "1", run("no_file.txt a b") != 0 ? "1" : "0");

    createFile("t.txt", "Hello World\n");
    run("t.txt World C++");
    check("Basic replacement", "Hello C++\n", readFile("t.txt.replace"));
    std::remove("t.txt"); std::remove("t.txt.replace");

    createFile("t.txt", "cat cat cat\n");
    run("t.txt cat dog");
    check("Multiple occurrences", "dog dog dog\n", readFile("t.txt.replace"));
    std::remove("t.txt"); std::remove("t.txt.replace");

    createFile("t.txt", "Hello World\n");
    run("t.txt xyz abc");
    check("No match -> unchanged", "Hello World\n", readFile("t.txt.replace"));
    std::remove("t.txt"); std::remove("t.txt.replace");

    createFile("t.txt", "original\n");
    run("t.txt original modified");
    check("Original file untouched", "original\n", readFile("t.txt"));
    std::remove("t.txt"); std::remove("t.txt.replace");

    createFile("t.txt", "hello\n");
    run("t.txt hello hello_world");
    check("s2 contains s1 -> no loop", "hello_world\n", readFile("t.txt.replace"));
    std::remove("t.txt"); std::remove("t.txt.replace");

    std::cout << "\n" << passed << " passed, " << failed << " failed." << std::endl;
    return (failed == 0 ? 0 : 1);
}
