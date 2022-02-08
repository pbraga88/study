#include <iostream>

using namespace std;

double calcWithLiteralsConstants(int rooms) {
    cout<<"\nEstimate: "<<endl;
    cout<<"Rooms: "<<rooms<<endl;

    cout<<"Price per room: R$"<<30<<endl;
    cout<<"Cost: R$"<<30*rooms<<endl;
    cout<<"Tax: R$"<<30*rooms*0.06<<endl;
    cout<<"=============================="<<endl;
    
    return (30*rooms)+(30*rooms*0.06);
}

double calcWithDeclaredConstants(int rooms) {
    double cost {0};
    const double price_per_room {30.0};
    const double tax {0.06};

    cout<<"\nEstimate: "<<endl;
    cout<<"Rooms: "<<rooms<<endl;

    cout<<"Price per room: R$"<<price_per_room<<endl;
    cout<<"Cost: R$"<<price_per_room*rooms<<endl;
    cout<<"Tax: R$"<<price_per_room*rooms*tax<<endl;
    cout<<"=============================="<<endl;

    cost = (price_per_room*rooms) + (price_per_room*rooms*tax);

    return cost;
}

int main() {
    cout<<"rooms: "<<endl;

    int numb_of_rooms {0};
    cin>>numb_of_rooms;

    // double final_price = calcWithLiteralsConstants(numb_of_rooms); 
    // cout<<"Total: R$"<<final_price<<endl;

    double final_price = calcWithDeclaredConstants(numb_of_rooms); 
    cout<<"Total: R$"<<final_price<<endl;

    return 0;
}