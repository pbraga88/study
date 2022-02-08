#include <iostream>

using namespace std;

double calcCost (int l_rooms, int s_rooms) {
    double total_cost {0.0};
    double cleaning_cost {0.0};
    double tax_cost {0.0};
    static double price_large_room = 35.0;
    static double price_small_room = 25.0;
    static double tax = 0.06;

    cleaning_cost = (l_rooms * price_large_room)+
        (s_rooms * price_small_room);
    cout<<"Cost: "<<cleaning_cost<<endl;
    
    tax_cost = cleaning_cost * tax;
    cout<<"Tax: "<<tax_cost<<endl;

    total_cost = cleaning_cost + tax_cost;

    return total_cost;
}

int main() {
    double cost {0};
    int large_rooms {0};
    int small_rooms {0};
    
    cout<<"Large Rooms: ";
    cin>>large_rooms;
    
    cout<<"Small Rooms: ";
    cin>>small_rooms;

    cost = calcCost(large_rooms, small_rooms);
    cout<<"Total estimate: "<<cost<<endl;

    return 0;
}