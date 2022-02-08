#include <iostream>

using namespace std;

int main() {
    int movie_rating [3][4] {
        {0, 4, 3, 5},
        {2, 3, 3, 5},
        {1, 4, 4, 5}
        };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout<<movie_rating[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}