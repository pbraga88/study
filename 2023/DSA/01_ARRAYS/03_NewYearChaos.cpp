/*
It is New Year's Day and people are in line for the Wonderland rollercoaster 
ride. Each person wears a sticker indicating their initial position in the 
queue from 1 to n. Any person can bribe the person directly in front of them to 
swap positions, but they still wear their original sticker. One person can 
bribe at most two others.

Determine the minimum number of bribes that took place to get to a given queue 
order. Print the number of bribes, or, if anyone has bribed more than two 
people, print "Too chaotic".

Example:

If person 2 bribes person 1, the queue will look like this: 2,1. Only 1 bribe 
is required. Print 1.

Person 5 had to bribe 3 people to get to the current position. Print 
"Too chaotic".

Function Description:

Complete the function "minimumBribes" in the editor below.

"minimumBribes" has the following parameter(s):
- int q[n]: the positions of the people after all bribes

Returns:

No value is returned. Print the minimum number of bribes necessary or "Too 
chaotic" if someone has bribed more than 2 people.

*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


void minimumBribes(std::vector<int> q) {
    size_t distance = 0;
    std::set<int> sorted_q;
    int min_bribes = 0;

    for(int i = q.size()-1; i>=0; i--) {
        if (distance>2) {
            std::cout<<"Too chaotic"<<std::endl;
            return;
        }
        sorted_q.insert(q.at(i));
        // Returns the distance between the two positions in the data-structure (set, in this example)
        distance = std::distance(sorted_q.begin(), sorted_q.find(q.at(i)));

        min_bribes+=distance;
    }
    std::cout<<min_bribes<<std::endl;
}


int main() {
    std::vector<int> queue = {1, 2, 5, 3, 7, 8, 6, 4};
    minimumBribes(queue);

    return 0;

}