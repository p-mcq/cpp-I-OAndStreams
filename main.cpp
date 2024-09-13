#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Standard Boolean output format" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "Standard bool output (noboolalpha) for (10 == 10): " << (10 == 10) << std::endl; // True
    std::cout << "Standard bool output (noboolalpha) for (10 != 10): " << (10 != 10) << std::endl; // False

    std::cout << "\nTrue/False Boolean output format" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << std::boolalpha; // Change to True/False
    std::cout << "True/False bool output (boolalpha) for (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "True/False bool output (boolalpha) for (10 != 10): " << (10 != 10) << std::endl;

    std::cout << "\nFormat Persists" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "True/False bool output (boolalpha) for (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "True/False bool output (boolalpha) for (10 != 10): " << (10 != 10) << std::endl;

    std::cout << "\nToggle back to default 0/1" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << std::noboolalpha; // Change back to 0/1
    std::cout << "Default bool output (noboolalpha) for (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "Default bool output (noboolalpha) for (10 != 10): " << (10 != 10) << std::endl;

    std::cout << "\nToggle to boolalpha using manipulators" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout.setf(std::ios::boolalpha); // Change to True/False
    std::cout << "True/False bool output (boolalpha) for (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "True/False bool output (boolalpha) for (10 != 10): " << (10 != 10) << std::endl;

    std::cout << "\nReset Flags to default" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << std::resetiosflags(std::ios::boolalpha); // Change back to 0/1
    std::cout << "Default bool output (noboolalpha) for (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "Default bool output (noboolalpha) for (10 != 10): " << (10 != 10) << std::endl;

    return 0;
}
