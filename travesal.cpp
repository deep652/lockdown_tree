#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node* createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int minDepth(Node *node) {
    if(node == NULL)
    {
        return 0;
    }
    else if( node->left==NULL && node->right==NULL)
    {
        return 1;
    }
    else if( !node->left)
    {
        return 1 + minDepth(node->right);
    }
    else if(!node->right)
    {
        return 1 + minDepth(node->left);
    }
    return  min( minDepth(node->left),minDepth(node->right))+1;
}
int main()
{
    Node *root = NULL, *ptr;

    root = createNode(1);;
    ptr = root;
    ptr->left = createNode(2);
    ptr->right = createNode(3);
    ptr = ptr->left;
    ptr->left = createNode(4);
    ptr->right = createNode(5);
    ptr=root->right;
    ptr->right = createNode(7);

    cout<<"Minimum Depth of the tree is "<< minDepth(root);

    return 0;
}
