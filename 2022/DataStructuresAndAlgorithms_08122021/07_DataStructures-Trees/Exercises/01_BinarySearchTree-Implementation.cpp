#include <iostream>
#include <string>

typedef struct bst {
    int value;
    struct bst* left;
    struct bst* right;
} BinaryST;

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


    // private:
        BinaryST *root, *auxPtr;

};

/*********** Class Definition End ****************/

void traverse(BinaryST *node) {
    std::cout<<node->value<<std::endl;
    if (node->left != NULL) {
        traverse(node->left);
    }
    if (node->right != NULL) {
        traverse(node->right);
    }
}

void print_tree(BinaryST* node) {

}

/*
      9
  4       20
1   6   15  170
*/
int main() {
    BST my_bst;

    my_bst.insert(9);
    my_bst.insert(4);
    my_bst.insert(6);
    my_bst.insert(20);
    my_bst.insert(170);
    my_bst.insert(15);
    my_bst.insert(1);


    traverse(my_bst.root);

    int nb = 200;
    BinaryST* node = my_bst.lookup(nb);
    if (node != NULL) {
        std::cout<<"value: "<<node->value<<std::endl;
        std::cout<<"left: "<<(node->left==NULL?-1:node->left->value)<<std::endl;
        std::cout<<"right: "<<(node->right==NULL?-1:node->right->value)<<std::endl;
    }

    return 0;
}