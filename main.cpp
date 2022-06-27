#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
        /*
         * Level Order traversal seeks to visit all nodes at a given "level" before printing the next layer.
         * Time = O(N)
         * Space = O(NlogN)
         */

        //Edge-case: Check to see if tree is empty
        if (root) {
            queue<Node*> discoveredNodes;
            //Enqueue current node
            discoveredNodes.push(root);

            //Dequeue first node
            while (!discoveredNodes.empty()) {
                Node *current = discoveredNodes.front();
                discoveredNodes.pop();
                std::cout << current->data << " ";
                //Build my queue of discovered child nodes
                if (current->left) {
                    discoveredNodes.push(current->left);
                }
                if (current->right) {
                    discoveredNodes.push(current->right);
                }
            }
        }
    }
}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.levelOrder(root);
    return 0;
}
