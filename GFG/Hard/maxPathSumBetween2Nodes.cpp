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

class Solution {
public:
    int maxSum = INT_MIN;
    int maxPathSumSolve(Node* root)
    {
        //Base Cases
        //1.Root doesn't exist
        //2.No leaf nodes
        if(root==NULL) return 0;
        if(!root->left && !root->right) return root->data;
        int lsum = maxPathSumSolve(root->left);
        int rsum = maxPathSumSolve(root->right);
        //if both leaves exist
        if(root->left && root->right)
        {    //total sum of subtree
            maxSum = max(maxSum, lsum+rsum+root->data);
            //max sum considering the root data and one side subtree 
            return max(lsum, rsum)+root->data;
        }
        //if only one side subtree exists
        if(root->left)
            return lsum+root->data;
        else
            return rsum+root->data;
    }
    int maxPathSum(Node* root)
    {
        // code here
        int res = maxPathSumSolve(root);
        if(root->left && root->right)return maxSum;
        return max(maxSum,res);
    }
};

//Driver Code
int main()
{
    Node *root = createNode(-15);
    root->left = createNode(5);
    root->right = createNode(6);
    root->left->left = createNode(-8);
    root->left->right = createNode(1);
    root->left->left->left = createNode(2);
    root->left->left->right = createNode(6);
    root->right->left = createNode(3);
    root->right->right = createNode(9);
    root->right->right->right= createNode(0);
    root->right->right->right->left= createNode(4);
    root->right->right->right->right= createNode(-1);
    root->right->right->right->right->left= createNode(10);
    Solution ob;
    cout << "Max pathSum of the given binary tree is "
         << ob.maxPathSum(root);
    return 0;
}