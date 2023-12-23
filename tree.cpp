#include <iostream>
using namespace std;

/*
TO DO:
DO INSERTION FOR TO THE RIGHT


*/


//Define class for the node on a tree
class Node {
    public:
        //data variables for node
        int data;
        
        //pointers make a memory address of type Node (We use pointsers so we don't infinitely make Nodes)
        Node *left, *right;
        
        //Constructor
        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        void Insert(int new_data) {
            //If current node is empty, insertion will make empty data into new_data
            if (this->data == NULL){
                this->data = new_data;
            }
            else{
                // if new data if less than current data, store new on left
                if (new_data < this->data){
                    //Check that left currently isn't storing anything
                    if (this->left == NULL) {
                        //set the this->left to be a node including new data
                        Node left_node(new_data);
                        //Sets Value of pointer by doing *
                        *left = left_node;
                    }
                    else {
                        //Recursive function that inserts into the left 
                        this->left->Insert(new_data);
                    }
                }
                else if (new_data > this->data) {
                    //put code here!!!
                }
                
            }
        }
};

void Insert(int new_data) {

}


int main() {
    Node root(5);
    return 0;
}