#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
int main()
{

#pragma region Writing to a File
    // std::ofstream outFile("test.txt", std::ios::trunc);
    // if (!outFile)
    // {
    //     std::cerr << "Error Creating output file" << std::endl;
    //     return 1;
    // }
    // std::string line{""};
    // std::cout << "Enter a line of text: ";
    // std::getline(std::cin, line);
    // outFile << line << std::endl;
    // outFile.close();
#pragma endregion

#pragma region Reading and writing to another file

    std::ofstream outFile("PineBarrens.txt", std::ios::trunc);
    std::ifstream inFile("pineBarrensSynopsis.txt");

    if (!outFile)
    {
        std::cerr << "Error Creating output file" << std::endl;
        return 1;
    }
    else if (!inFile)
    {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
    // std::string line;

    // while (std::getline(inFile, line))
    // {
    //     outFile << line << std::endl;
    // }

    // OR
    char c;
    while (inFile.get(c))
    {
        outFile.put(c);
    }

    outFile.close();
    inFile.close();

#pragma endregion
    return 0;
}
