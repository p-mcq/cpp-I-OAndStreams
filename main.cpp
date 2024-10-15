#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

int main()
{
    // int num{};
    // double total{};
    // std::string name{};

    // std::string info{"Moe 100 123.45"};
    // std::istringstream iss{info};

    // iss >> name >> num >> total;
    // std::cout << std::setw(10) << std::left << name
    //           << std::setw(5) << num
    //           << std::setw(10) << total << std::endl;
    // std::cout << "----------------------------------" << std::endl;

    // std::ostringstream oss{};
    // oss << std::setw(10) << std::left << name
    //     << std::setw(5) << num
    //     << std::setw(10) << total << std::endl;
    // std::cout << oss.str() << std::endl;

    // std::cout << "----------------------------------" << std::endl;

    // Data Validation Example
    int value{};
    std::string entry{};
    bool done{false};
    do
    {
        std::cout << "Enter an integer: ";
        std::cin >> entry;
        std::istringstream validator{entry};
        if (validator >> value)
        {
            done = true;
        }
        else
        {
            std::cout << "Sorry, that's not an integer" << std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!done);

    std::cout << "You entered: " << value << std::endl;
    return 0;
}
