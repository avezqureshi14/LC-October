#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createBT(Node *root)
{
    int data;
    cout << "Enter the data " << endl;
    cin>>data;
    if (data == -1)
    {
        return root;
    }
    root = new Node(data);
    cout << "Enter the data to the left of " << data << endl;
    root->left = createBT(root);
    cout << "Enter the data to the right of " << data << endl;
    root->right = createBT(root);
    return root;
}

void preOrder(Node*root){
    if (root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

pair<int, bool> solve(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        pair<int, bool> p = {0, true};
        return p;
    }
    pair<int, bool> left = solve(root->left);
    pair<int, bool> right = solve(root->right);
    int ans = left.first + right.first;
    if (ans == root->data && left.second && right.second)
    {
        return {ans, true};
    }
    else
    {
        return {ans, false};
    }
}

bool isSumTree(Node *root)
{
    return solve(root).second;
}

int main()
{
    Node*root = createBT(root);
    preOrder(root);
    // cout<<isSumTree(root);
    return 0;
}

// 3 1 -1 -1 2 -1 -1