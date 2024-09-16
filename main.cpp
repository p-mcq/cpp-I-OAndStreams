// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
struct City
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

const int totalWidth = 72;
const int countryWidth = 20;
const int cityWidth = 20;
const int populationWidth = 20;
const int costWidth = 12;

void PrintTitleAndTableHeaders(const Tours &tours)
{
    int titleWidth = tours.title.length();
    std::cout << std::setw((totalWidth - titleWidth) / 2) << "" << std::setw(titleWidth) << tours.title << std::endl;
    std::cout << std::endl;

    std::cout << std::setw(countryWidth) << std::left << "Country"
              << std::setw(cityWidth) << std::left << "City"
              << std::setw(populationWidth) << std::right << "Population"
              << std::setw(costWidth) << std::right << "Price"
              << std::endl;

    std::cout << std::setw(totalWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void PrintCountry(const Country &country)
{
    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < country.cities.size(); i++)
    {
        std::cout << std::setw(countryWidth) << std::left << ((i == 0) ? country.name : "")
                  << std::setw(cityWidth) << std::left << country.cities[i].name
                  << std::setw(populationWidth) << std::right << country.cities[i].population
                  << std::setw(costWidth) << std::right << country.cities[i].cost << std::endl;
    }
    std::cout << std::setw(72) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

int main()
{
    Tours tours{"Tour Ticket Prices from Miami",
                {
                    {
                        "Colombia",
                        {{"Bogota", 8778000, 400.98},
                         {"Cali", 2401000, 424.12},
                         {"Medellin", 2464000, 350.98},
                         {"Cartagena", 972000, 345.34}},
                    },
                    {
                        "Brazil",
                        {{"Rio De Janeiro", 13500000, 567.45},
                         {"Sao Paulo", 11310000, 975.45},
                         {"Salvador", 18234000, 855.99}},
                    },
                    {
                        "Chile",
                        {{"Valdivia", 260000, 569.12},
                         {"Santiago", 7040000, 520.00}},
                    },
                    {"Argentina", {{"Buenos Aires", 3010000, 723.77}}},
                }};

    // Unformatted display so you can see how to access the vector elements
    // std::cout << tours.title << std::endl;
    // for (auto country : tours.countries)
    // { // loop through the countries
    //     std::cout << country.name << std::endl;
    //     for (auto city : country.cities)
    //     { // loop through the cities for each country
    //         std::cout << "\t" << city.name
    //                   << "\t" << city.population
    //                   << "\t" << city.cost
    //                   << std::endl;
    //     }
    // }

    // std::cout << std::endl
    //           << std::endl;

    // Formatted display
    PrintTitleAndTableHeaders(tours);
    for (auto const country : tours.countries)
    {
        PrintCountry(country);
    }
    return 0;
}