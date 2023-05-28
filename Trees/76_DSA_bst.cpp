#include <iostream>
using namespace std;
#include <queue>
struct node
{
    int data;
    node *left, *right;
};

// to insert node in bst
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = new node();
        root->data = data;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// to check wheather a node given value exists in bst or not
bool search(node *root, int data)
{
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

// Some auxillary operations on bst
int findMin(node *root)
{
    if (root == NULL)
        return INT32_MIN;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int findMax(node *root)
{
    if (root == NULL)
        return INT32_MAX;
    // else if (root->right == NULL)
    // {
    //     return root->data;
    // }
    // return findMax(root->right);
    
    // while(root->right!=NULL){
    //     root = root->right;
    // }
    // return root->data;

    node* current = root;
    while (current->right != NULL)
        current = current->right;
     
    return (current->data);
}
int findHeight(node *root)
{
    if (root == NULL)
        return -1;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

// Traversals in bst:-
// 1.) Breadth first search
void lavelOrder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
        q.pop();
    }
    cout << endl;
}

// 2.) depth first search
void preOrderTraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void inOrderTraversal(node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

// functions used in isBst function
bool isSubTreeLesser(node *root, int data)
{
    if (root == NULL)
        return true;
    if (root->data <= data && isSubTreeLesser(root->left, data) && isSubTreeLesser(root->right, data))
        return true;
    return false;
}
bool isSubTreeGreater(node *root, int data)
{
    if (root == NULL)
        return true;
    if (root->data <= data && isSubTreeGreater(root->left, data) && isSubTreeGreater(root->right, data))
        return true;
    return false;
}
bool isBst(node *root)
{
    if (root == NULL)
        return true;
    if (isSubTreeLesser(root->left, root->data) && isSubTreeGreater(root->right, root->data) && isBst(root->left) && isBst(root->right))
        return true;
    return false;
}

// function to delete node from bst
node *deleteNode(node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data < data)
    {
        root->right = deleteNode(root->right, data);
    }
    else if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *temp = new node();
            temp->data = findMin(root->right);
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// functions used in finding inorder predecessor and sucessor
node *find(node *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;
    if (data < root->data)
    {
        return find(root->left, data);
    }
    return find(root->right, data);
}
int getSuccessor(node *root, int data)
{
    node *current = find(root, data);
    if (current == NULL)
        return INT16_MIN;
    if (current->right != NULL)
    {
        return findMin(current->right);
    }
    node *successor = NULL, *ancestor = root;
    while (ancestor != current)
    {
        if (ancestor->data > current->data)
        {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else
        {
            ancestor = ancestor->right;
        }
    }
    if(successor!=NULL)return successor->data;
    else return INT16_MIN;
}
int getPredecessor(node *root, int data)
{
    node *current = find(root, data);
    if (current == NULL)
        return INT16_MIN;
    if (current->left != NULL)
    {
        return findMax(current->left);
    }
    node *predecessor = NULL, *ancestor = root;
    while (ancestor != current)
    {
        if (ancestor->data > current->data)
        {
            ancestor = ancestor->left;
        }
        else
        {
            predecessor = ancestor;
            ancestor = ancestor->right;
        }
    }
    if(predecessor!=NULL)return predecessor->data;
    else return INT16_MIN;
}

// driver code
int main()
{
    node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 15);
    root = insert(root, 14);
    root = insert(root, 17);
    // cout << findHeight(root) << endl;
    lavelOrder(root);

    inOrderTraversal(root);
    cout << endl;
    // root = deleteNode(root, 2);
    // inOrderTraversal(root);
    cout << getSuccessor(root, 14);
    cout << endl;
    cout << getPredecessor(root, 17);
    cout << endl;
    

    return 0;
}