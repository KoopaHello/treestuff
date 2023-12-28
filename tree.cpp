#include <iostream>
#include <string>
using namespace std;

//Define class for the node on a tree
class Node {
    public:
        //data variables for node
        int data;

        //pointers make a memory address of type Node (We use pointsers so we don't infinitely make Nodes)
        Node* left;
        Node* right;
        bool hasLeft;
        bool hasRight;
        //* maybe just create right and left nodes inside of insertion function? LOL, am i an idiot?

        //Constructor
        Node(int data) {
            this->data = data;
            hasLeft = false;
            hasRight = false;
            left = NULL;
            right = NULL;
        }
};


Node insert(Node root_node, int new_data) {
    int data = root_node.data;
    if (0 == 1) {
        root_node.data = new_data;
    }
    else {
        if (new_data < data) {
            if (!root_node.hasLeft) {
                root_node.left = new Node(new_data);
                root_node.hasLeft = true;
            }
            else {
                *(root_node.left) = insert(*(root_node.left), new_data);
            }
        }

        if (new_data > data) {
            if (!root_node.hasRight) {
                root_node.right = new Node(new_data);
                root_node.hasRight = true;
            }
            else {
                *(root_node.right) = insert(*(root_node.right), new_data);
            }
        }
    }
    return root_node;
}

int level = 1;

string drawTree(Node root_node){
    string tree = " ";
    if (root_node.data == NULL) {
        tree = " ";
    }
    else {
        tree = to_string(root_node.data);
        if (root_node.hasLeft) {
            string leftString = "  \n/\n" + drawTree(*root_node.left);
            tree = tree + leftString;
        }
        if (root_node.hasRight){
            string rightString = "  \n\\\n" + drawTree(*root_node.right);
            tree = tree + rightString;
        }
    }
    return tree;
}


int main() {
    cout << "WELCOME TO THE FOREST \n";
    Node root(5);
    cout << root.data << "\n";
    root = insert(root, 3);
    //Node left_node = *(root.left);
    cout << root.left << " does this workkkkkk \n";
    cout << root.left->data << " HELLO SPECIAL FRIEND \n";
    root = insert(root, 2);
    //Node left_nodee = *root.left;
    cout << root.left->data << " repeat of special friend \n";
    cout << root.left->left->data << " new NODE PALSS!!! \n";

    root = insert(root, 7);

    cout << root.right->data << "\n";


    //traverse via inorder
    cout << drawTree(root) << endl;


    return 0;
}
