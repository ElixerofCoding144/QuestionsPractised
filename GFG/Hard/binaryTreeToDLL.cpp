#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data)
{
    struct Node* node = new(struct Node);
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

class Solution
{
    public: 
    Node *prev = NULL;
    Node *head = NULL;
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        if(!root) return NULL;
        bToDLL(root->left);
        //applicable for the first node
        if(!prev) head = root;
        //double link
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        bToDLL(root->right);
        return head;
    }
};

void printList(Node *root) 
{ 
    while (root != NULL) 
    { 
        cout<<"\t"<<root->data; 
        root = root->right; 
    } 
}

// Driver code 
int main(void) 
{ 
    // Let us create the tree 
    // shown in above diagram 
    Node *root = createNode(10); 
    root->left = createNode(12); 
    root->right = createNode(15); 
    root->left->left = createNode(25); 
    root->left->right = createNode(30); 
    root->right->left = createNode(36); 
    Solution ob;
    Node *head = ob.bToDLL(root); 

    cout << "\n\n\t\tDLL Traversal\n\n"; 
    printList(head); 
    return 0; 
}
