#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main()
{
    std::fstream inFile;
    std::string name;
    std::string lineToReadInPoem;
    int number;
    double decimal;
    int lineCount = 1;

    // inFile.open("input.txt");
    // if (!inFile)
    // {
    //     std::cerr << "Unable to open file input.txt";
    //     return 1;
    // }

    // while (inFile >> name >> number >> decimal)
    // {
    //     std::cout << std::setw(10) << std::left << name
    //               << std::setw(10) << std::left << number
    //               << std::setw(10) << std::left << decimal << std::endl;
    // }

    inFile.open("poem.txt", std::ios::in);
    if (!inFile)
    {
        std::cerr << "Unable to open file poem.txt";
        return 1;
    }

    while (std::getline(inFile, lineToReadInPoem))
    {
        if (lineCount > 2)
        {
            std::cout << lineToReadInPoem << std::endl;
        }
        else
        {
            std::cout << std::setw(15) << std::left << "" << lineToReadInPoem << std::endl;
        }
        lineCount++;
    }

    inFile.close();

    return 0;
}
