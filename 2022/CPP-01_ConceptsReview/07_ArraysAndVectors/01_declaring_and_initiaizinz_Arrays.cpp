#include <iostream>

using namespace std;

int main() {
    int test_01 [5] {100, 99, 98, 97, 96};
    cout<<"test_01 values: "<<endl;
    for(int i = 0; i < sizeof(test_01)/sizeof(test_01[0]); i++) {
        cout<<test_01[i]<<" ";
    }

    // Init first two elements to 3 and 5 and remainder to 0
    int test_02 [10] {3,5};
    cout<<"\ntest_02 values: "<<endl;
    for(int i = 0; i < sizeof(test_02)/sizeof(test_02[0]); i++) {
        cout<<test_02[i]<<" ";
    }

    // Init all to 0
    const int days_in_year {365};
    int test_03 [days_in_year] {0};
    cout<<"\ntest_03 values: "<<endl;
    for(int i = 0; i < sizeof(test_03)/sizeof(test_03[0]); i++) {
        cout<<test_03[i]<<" ";
    }

    // Size is automatically calculated
    int test_04 [] {1, 2, 3, 4, 5};
    cout<<"\ntest_04 values: "<<endl;
    for(int i = 0; i < sizeof(test_04)/sizeof(test_04[0]); i++) {
        cout<<test_04[i]<<" ";
    }
    cout<<endl;

    // Init all to 0
    int test_05 [5] {};
    cout<<"\ntest_05 values: "<<endl;
    for(int i = 0; i < sizeof(test_05)/sizeof(test_05[0]); i++) {
        cout<<test_05[i]<<" ";
    }
    cout<<endl;
    return 0;
}