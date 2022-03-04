#include <iostream>
#include <string>
#include <set>
#include <map>

class BST_STL {
    public: 
        BST_STL() {};
        ~BST_STL() {};

        void insert(int val) {
            bst.insert(val);
        }
        int lookup(int val) {
            std::set<int>::iterator it;
            it = bst.find(val);
            return *it;
        }
        void remove(int val) {
            bst.erase(val);
        }

        std::set<int> get_bst() {
            return bst;
        }

    private:
        std::set<int> bst;
};

int main() {
    BST_STL my_bst;
    my_bst.insert(10);
    my_bst.insert(9);
    my_bst.insert(11);
    my_bst.insert(1);
    my_bst.insert(100);
    // int nb = my_bst.lookup(10);
    // std::cout<<nb<<std::endl;

    std::set<int> my_set = my_bst.get_bst();
    std::set<int>::iterator it = my_set.begin();
    for (it; it != my_set.end(); it++) {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    my_bst.remove(11);
    my_set = my_bst.get_bst();
    for (it=my_set.begin(); it != my_set.end(); it++) {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    /* using std::greater<int> to get values sorted from major to minor*/
    std::set<int, std::greater<int>> set_reversed;
    set_reversed.insert(10);
    set_reversed.insert(9);
    set_reversed.insert(11);
    set_reversed.insert(1);
    set_reversed.insert(100);
    std::set<int, std::greater<int>>::iterator it_rev;
    for (it_rev = set_reversed.begin(); it_rev != set_reversed.end(); it_rev++) {
        std::cout<<*it_rev<<" ";
    }
    std::cout<<std::endl;

    return 0;
}