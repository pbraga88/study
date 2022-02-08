#include <iostream>
#include <vector>

using namespace std;

void oneDimensionVectors(vector<int> scores) {
    {   // Arrays syntax
        cout<<"Using Arrays syntax"<<endl;
        for (int i = 0; i < scores.size(); i++) {
            cout<<scores[i]<<" ";
        }
        cout<<endl;
    }
    {
        // Vectors syntax - Using OO Methods
        cout<<"\nUsing Vectors Method 'vector.a(position)'"<<endl;
        for (int i = 0; i < scores.size(); i++) {
            cout<<scores.at(i)<<" ";
        }
        cout<<endl;

        cout<<"\nChanging values using 'vector.a(position) = value'"<<endl;
        for (int i = 0; i < scores.size(); i++) {
            scores.at(i) = scores.at(i)/2;
        }
        for (int i = 0; i < scores.size(); i++) {
            cout<<scores.at(i)<<" ";
        }
        cout<<"\nThere are "<<scores.size()<<" values in the vector"<<endl;
        cout<<endl;

        cout<<"Grow the array dynamically using push_back method"<<endl;
        cout<<"This method will add to the end of the vector"<<endl;
        scores.push_back(80);
        scores.push_back(90);
        for (int i = 0; i < scores.size(); i++) {
            cout<<scores.at(i)<<" ";
        }
        cout<<"\nThere are "<<scores.size()<<" values in the vector"<<endl;
        cout<<endl;

        cout<<"Get more imput from user and uptade position '0'"<<endl;
        cin>>scores.at(0);
        for (int i = 0; i < scores.size(); i++) {
            cout<<scores.at(i)<<" ";
        }
        cout<<"\nThere are "<<scores.size()<<" values in the vector"<<endl;
        cout<<endl;
    }

    {
        // Read from user and push_back to scores_new vector
        vector<int> scores_new {};
        int add_score {0};
        cout<<"scores_new size = "<<scores_new.size()<<endl;
        cout<<"Enter value:"<<endl;
        cin>>add_score;
        scores_new.push_back(add_score);
        for (int i = 0; i < scores_new.size(); i++) {
            cout<<scores_new.at(i)<<" ";
        }
        cout<<"\nscores_new size = "<<scores_new.size()<<endl;
    }
}

void twoDimensionsVectors(vector<vector<int>> ratings) {
    for (int i = 0; i < ratings.size(); i++) {
        for (int j = 0; j < ratings.at(i).size(); j++) {
            cout<<ratings.at(i).at(j)<<" ";
        }
        cout<<endl;
    }


}
int main() {
    vector<int> scores {100, 95, 99 ,87 ,88, 78, 100};
    // oneDimensionVectors(scores);
    
    vector<vector<int>> ratings
    {
        {1, 2, 3, 4, 5}, 
        {2, 3, 2}, 
        {2, 1, 4, 5, 5}
    };
    twoDimensionsVectors(ratings);

    // scores.insert(scores.begin(), 10);
    // for (int i = 0; i < scores.size(); i++) {
    //     cout<<scores.at(i)<<" ";
    // }
    // cout<<endl;

    return 0;
}