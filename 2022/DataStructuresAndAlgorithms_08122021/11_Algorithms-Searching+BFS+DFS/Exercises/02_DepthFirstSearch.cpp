#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <set>

typedef struct bst {
    int value;
    struct bst* left;
    struct bst* right;
} BinaryST;

typedef struct llist {
    BinaryST *bst; 
    struct llist* next;
} LinkedList;

/* O(log n) */
class BST {
    public:
        BST() {
            root = NULL;
        }
        ~BST() {/* To write freeing routines*/}

        void create_root(int val) {
            root = new BinaryST;
            root->value = val;
            root->left = NULL;
            root->right = NULL;
        }

        void insert(int val) {
            if (root == NULL) {
                create_root(val);
            }
            else {
                auxPtr = root;
                while (auxPtr != NULL) {
                    if (val < auxPtr->value) {
                        if (auxPtr->left == NULL) {
                            auxPtr->left = new BinaryST;
                            auxPtr = auxPtr->left;
                            break;
                        }
                        auxPtr = auxPtr->left;
                    }
                    else {
                        if (auxPtr->right == NULL) {
                            auxPtr->right = new BinaryST;
                            auxPtr = auxPtr->right;
                            break;
                        }
                        auxPtr = auxPtr->right;
                    }
                }
                auxPtr->value = val;
                auxPtr->left = NULL;
                auxPtr->right = NULL;
            }
        }

        BinaryST* lookup (int val) {
            if (root == NULL) {
                return NULL; //error
            }
            
            auxPtr = root;
            while (auxPtr != NULL) {
                if (val == auxPtr->value) {
                    return auxPtr;
                }
                else if (val < auxPtr->value) {
                    auxPtr = auxPtr->left;
                }
                else {
                    auxPtr = auxPtr->right;
                }
            }
            return NULL; //error
        }

        std::list<int> breadthFirstSearch() {
            auxPtr = this->root;
            std::list<int> r_list;
            std::queue<BinaryST> bst_queue;
            bst_queue.push(*auxPtr);
            while(bst_queue.size() > 0) {
                *auxPtr = bst_queue.front();
                bst_queue.pop();
                r_list.push_back(auxPtr->value);
                if (auxPtr->left != NULL) {
                    bst_queue.push(*auxPtr->left);
                }
                if (auxPtr->right != NULL) {
                    bst_queue.push(*auxPtr->right);
                }
            }
            return r_list;
        }
        std::list<int> breadthFirstSearchRecursion(std::queue<BinaryST> &r_queue, 
                                                   std::list<int> &bst_list) {
            if(r_queue.size()<= 0) {
                return bst_list;
            }
            BinaryST currenNode; 
            currenNode = r_queue.front();
            r_queue.pop();
            bst_list.push_back(currenNode.value);
            if(currenNode.left != NULL) {
                r_queue.push(*currenNode.left);
            }
            if(currenNode.right != NULL) {
                r_queue.push(*currenNode.right);
            }

            return this->breadthFirstSearchRecursion(r_queue, bst_list);
        }

        // DFS - InOrder
        std::list<int> depthFirstSearch_InOrder(BinaryST &node, std::list<int> &r_list){
            if(node.left != NULL) {
                this->depthFirstSearch_InOrder(*node.left, r_list);
            }
            r_list.push_back(node.value);
            
            if(node.right != NULL) {
                this->depthFirstSearch_InOrder(*node.right, r_list);
            }
            return r_list;
        }
        //DFS - PostOrder
        std::list<int> depthFirstSearch_PostOrder(BinaryST &node, std::list<int> &r_list){
            if(node.left != NULL) {
                this->depthFirstSearch_PostOrder(*node.left, r_list);
            }            
            if(node.right != NULL) {
                this->depthFirstSearch_PostOrder(*node.right, r_list);
            }
            r_list.push_back(node.value);

            return r_list;
        }
        //DFS - PreOrder
        std::list<int> depthFirstSearch_PreOrder(BinaryST &node, std::list<int> &r_list){
            r_list.push_back(node.value);
            if(node.left != NULL) {
                this->depthFirstSearch_PreOrder(*node.left, r_list);
            }            
            if(node.right != NULL) {
                this->depthFirstSearch_PreOrder(*node.right, r_list);
            }
                        
            return r_list;
        }

/*
      9
  4       20
1   6   15  170
*/

        BinaryST getroot() {
            BinaryST root_ret = *root;
            return root_ret;
        }

    private:
        BinaryST *root, *auxPtr;

};

int main() {
    BST my_bst;

    my_bst.insert(9);
    my_bst.insert(4);
    my_bst.insert(6);
    my_bst.insert(20);
    my_bst.insert(170);
    my_bst.insert(15);
    my_bst.insert(1);

    BinaryST root = my_bst.getroot();
    // std::queue<BinaryST> my_tree;
    // my_tree.push(my_bst.getroot());
    std::list<int> my_list;

    std::list<int> BFS_list = my_bst.depthFirstSearch_InOrder(root, my_list);
    std::cout<<"DFS - In Order: ";
    for(auto val: BFS_list) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    my_list.erase(my_list.begin(), my_list.end());
    BFS_list = my_bst.depthFirstSearch_PreOrder(root, my_list);
    std::cout<<"DFS - Pre Order: ";
    for(auto val: BFS_list) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    my_list.erase(my_list.begin(), my_list.end());
    BFS_list = my_bst.depthFirstSearch_PostOrder(root, my_list);
    std::cout<<"DFS - Post Order: ";
    for(auto val: BFS_list) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;


    return 0;
}