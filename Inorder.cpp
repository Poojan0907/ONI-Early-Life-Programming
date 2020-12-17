#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



void inOrder(BinaryTreeNode<int> *root) {
	//Base Case 
    if(root == NULL) return;
    
    //Previous Element Recursively
    inOrder(root->left);

    //Center Element
	cout << root->data << " ";
    
    //Next Element Recursively
    inOrder(root->right);
}


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
/*

## Solution: Inorder Tree Traversal
### Time Complexity: O(n)
### Space Complexity: O(n)
### Input: In the Preorder format and for non existing child use -1;
For exampe tree               5
                            /   \
                           6    10
                         /  \   
                        2    3
                              \
                               9

###Input would be: 5 6 10 2 3 -1 -1 <= (for child of 10) -1 -1 <= (child of 2) -1 <= (left chld of 3) 9 -1 -1 <= (child of 9)

5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
*/
int main() {
    BinaryTreeNode<int>* root = takeInput();
    inOrder(root);
}
