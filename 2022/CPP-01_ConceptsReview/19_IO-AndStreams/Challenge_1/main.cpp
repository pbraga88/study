// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void ruler() {
    std::cout << "\n12345678901234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;
    std::cout<<std::endl;
}
static int ruler_length = 80;

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janeiro", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                    },
                },
                    { "Argentina", { 
                        { "Buenos Aires", 3010000, 723.77 } 
                    } 
                },
            }
    };

    // print the rules at the top
    ruler();
    int std_width = 20;
    int end_position_title = (ruler_length/2) + (tours.title.size()/2);
    // Unformatted display so you can see how to access the vector elements
    std::cout<< std::setw(end_position_title) << tours.title << std::endl;
    std::cout<<std::setw(std_width)<<std::left<<"Country"
             <<std::setw(std_width)<<std::left<<"City"
             <<std::setw(std_width)<<std::right<<"Population"
             <<std::setw(std_width)<<std::right<<"Price"
             <<std::endl;
    std::cout<<std::setw(ruler_length)<<std::setfill('-')<<'-'<<std::endl;
    for(auto country : tours.countries) { // loop through the countries and print the first city
        std::cout<<std::setw(std_width)<<std::left << std::setfill(' ')<<country.name
                     <<std::setw(std_width)<<std::left<< country.cities.at(0).name
                     <<std::setw(std_width)<<std::right<< country.cities.at(0).population
                     <<std::setw(std_width)<<std::right<< country.cities.at(0).cost
                     <<std::endl;
        // loop through the cities (starting from the second) for each country
        for(auto it = country.cities.begin() + 1; it != country.cities.end(); ++it) {
            std::cout<<std::setw(std_width)<<std::left<< " " 
                     <<std::setw(std_width)<<std::left<< it->name
                     <<std::setw(std_width)<<std::right<< it->population
                     <<std::setw(std_width)<<std::right<<std::fixed<<std::setprecision(2)<<it->cost
                     <<std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}