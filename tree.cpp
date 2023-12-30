#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

//Define class for the node on a tree
class Node {
    public:
        //data variables for node
        int data;

        //root node is level 0
        int level;

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

int calculateLevel(Node root_node){
    int level = 0;
    int rightLevel;
    int leftLevel;

    if (root_node.hasLeft){
        int leftLevel = calculateLevel(*root_node.left);
    }
    if (root_node.hasRight){
        int rightLevel = calculateLevel(*root_node.right);
    }

    if (rightLevel > leftLevel){
        level += rightLevel;
    }
    else{
        level += leftLevel;
    }
    return level;
}

/* //! prior terrible implementation of printing, main problem: that i tried to return a massive tree string instead of printing as the function goes along
string drawTree(Node root_node){
    string tree = "";
    if (root_node.data == NULL) {
        tree = "";
    }
    else {
        tree = to_string(root_node.data);
        if (root_node.hasLeft && root_node.hasRight){
            tree = tree + "\n" +
                   "|\\\n" +
                   drawTree(*root_node.left);

            //insert bc \n will be considered

            //find the position to insert right node at
            //!something wrong with this code
            int backSlashIndex;
            int priorCharIndex;
            for (char character : tree){
                if (character == '\\') {
                    backSlashIndex = tree.find(character);
                    cout << "BACK SLASH INDEX: " + backSlashIndex << endl; 
                    if (tree[backSlashIndex + 1] != ' ') {
                        //for loop to find where \ is along the row
                        int priorCharIndex;
                        bool priorCharFound = false;
                        int countIndex = backSlashIndex;
                        while (!priorCharFound){
                            countIndex -= 1;
                            if (tree[countIndex] != ' '){
                                priorCharFound = true;
                                priorCharIndex = tree[countIndex];
                            }
                        }
                    }
                }
                break;
            }

            int ammountOfSpaces = backSlashIndex - priorCharIndex;
            cout << ammountOfSpaces << endl;
            string space = " ";
            int rightSpace = backSlashIndex + 1;
            if (ammountOfSpaces <= 1){
                tree.insert(rightSpace, space + drawTree(*root_node.right));
            }
            else{
                string multSpaces(1, ' ');
                tree.insert(rightSpace, multSpaces + drawTree(*root_node.right));
            }
        }
        else if (root_node.hasLeft && !root_node.hasRight) {
            //string leftString = "  \n/\n" + drawTree(*root_node.left);
            //tree = tree + leftString;
            tree = tree + "\n" +
                   "|\n" +
                    drawTree(*root_node.left);
        }
        else if (root_node.hasRight && !root_node.hasLeft){
            tree = tree + "\n" +
                   " \\\n" +
                   "   " + drawTree(*root_node.right);
        }
    }
    cout << "tree debug: " + tree << "\n";
    return tree;
}
*/

void printTree(string prefix, Node node, bool isLeft) {
    if (node.data != NULL) {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        cout << node.data << endl;
        if (node.hasLeft == true) {
            printTree( prefix + (isLeft ? "│   " : "    "), *node.left, true);
        }
        if (node.hasRight == true) {
            printTree( prefix + (isLeft ? "│   " : "    "), *node.right, false);
        }
    }
}

int main() {
    cout << "WELCOME TO THE FOREST \n";
    cout << "Instructions--\ncreate[int] : creates a new tree with a root node of [int]\ninsert[int] : inserts a new node of [int] into the tree\nprint : print the tree\nexit : exits the program" << endl;
    bool run = true;
    string input;
    Node root(1);
    while (run){
        cin >> input;
        if (input.find("create") != -1) {
            int nodeNum = 0;
            for (char c : input) {
                if (c >= '0' && c <= '9'){
                    nodeNum = nodeNum * 10 + (c - '0');
                }
            }
            Node newNode(nodeNum);
            root = newNode;
            //cout << "created root of " + nodeNum << endl;
        }
        else if (input == "print") {
            printTree("", root, false);
        }        
        else if (input.find("insert") != -1) {

            int nodeNum = 0;
            for (char c : input) {
                if (c >= '0' && c <= '9'){
                    nodeNum = nodeNum * 10 + (c - '0');
                }
            }

            //int nodeNum = input[6] - '0';
            root = insert(root, nodeNum);
            //cout << "inserted node of " + nodeNum << endl;
        }
        else if (input == "exit") {
            run = false;
        }
        else {
            cout << "incorrect input" << endl;
        }
    }

    /*
    Node root(5);
    cout << root.data << "\n";
    root = insert(root, 4);
    //Node left_node = *(root.left);
    cout << root.left << " does this workkkkkk \n";
    cout << root.left->data << " HELLO SPECIAL FRIEND \n";
    root = insert(root, 2);
    //Node left_nodee = *root.left;
    cout << root.left->data << " repeat of special friend \n";
    cout << root.left->left->data << " new NODE PALSS!!! \n";

    //cout << root.right->data << "\n";

    cout << calculateLevel(root) << "HOWS YOUR LEVEL?? \n";

    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 10);

    //traverse via inorder
    printTree("", root, false);
    */


    return 0;
}
