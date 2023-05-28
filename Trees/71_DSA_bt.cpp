#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class binaryTree
{
public:
    node *root;
    binaryTree()
    {
        root = nullptr;
    }
    void addNode(int data);     // Done
    // depth first search
    void preOrderTraversal(node *focusNode);    // Done  
    void inOrderTraversal(node *focusNode);     // Done
    void postOrderTraversal(node *focusNode);   // Done  
    // breadth first search
    void levelOrderTraversal(node *focusNode);  
    void printCurrentLevel(node *root,int l);
    int findHeight(node *root);     // Done
    int findMin(node *root);        // Done
    int findMax(node *root);        // Done
    void deleteNode(int key);


    
};
void binaryTree::addNode(int data)
{
    node *newNode = new node(data);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    node *focusNode = root, * parent;
    while (1)
    {
        parent = focusNode;
        if (data < focusNode->data)
        {
            focusNode = focusNode->left;
            if (focusNode == nullptr)
            {
                parent->left = newNode;
                return;
            }
        }
        else
        {
            focusNode = focusNode->right;
            if (focusNode == nullptr)
            {
                parent->right = newNode;
                return;
            }
        }
    }
}
void binaryTree::preOrderTraversal(node *focusNode)
{
    if (focusNode != nullptr)
    {
        cout << focusNode->data << " ";
        preOrderTraversal(focusNode->left);
        preOrderTraversal(focusNode->right);
    }
}
void binaryTree::inOrderTraversal(node *focusNode)
{
    if (focusNode != nullptr)
    {
        inOrderTraversal(focusNode->left);
        cout << focusNode->data << " ";
        inOrderTraversal(focusNode->right);
    }
}
void binaryTree::postOrderTraversal(node *focusNode)
{
    if (focusNode != nullptr)
    {
        postOrderTraversal(focusNode->left);
        postOrderTraversal(focusNode->right);
        cout << focusNode->data << " ";
    }
}
int binaryTree::findHeight(node *root){
    if(root==NULL)return -1;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    if(lh>rh)return lh+1;
    return rh+1;
}
void binaryTree::printCurrentLevel(node *root, int l){
    if(root == NULL)return;
    if(l==0)cout<<root->data<<" ";
    else{
        printCurrentLevel(root->left,l-1);
        printCurrentLevel(root->right,l-1);
    }
}
void binaryTree::levelOrderTraversal(node *root){
    int h = findHeight(root);
    for (int i = 0; i <=h; i++)
    {
        printCurrentLevel(root,i);
    }
    cout<<endl;
    
}
int binaryTree::findMin(node *root){
    if(root==NULL)return INT32_MAX;
    int minVal = root->data;
    int left = findMin(root->left);
    int right = findMin(root->right);
    if(left<minVal)minVal = left;
    if (right<minVal)minVal = right;
    return minVal;

}
int binaryTree::findMax(node *root){
    if(root==NULL)return INT32_MIN;
    int maxVal = root->data;
    int left = findMax(root->left);
    int right = findMax(root->right);
    if(left>maxVal)maxVal = left;
    if (right>maxVal)maxVal = right;
    return maxVal;
}
void binaryTree::deleteNode(int key){
    
}

int main()
{
    binaryTree bt;
    bt.addNode(5);
    bt.addNode(3);
    bt.addNode(4);
    bt.addNode(6);
    bt.addNode(2);
    bt.preOrderTraversal(bt.root);
    cout<<endl;
    bt.inOrderTraversal(bt.root);
    cout<<endl;
    bt.postOrderTraversal(bt.root);
    cout<<endl;
    cout<<bt.findHeight(bt.root)<<endl;
    bt.levelOrderTraversal(bt.root);
    cout<<bt.findMin(bt.root)<<endl<<bt.findMax(bt.root)<<endl;
    return 0;
}


















// #include <iostream>

// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         this->left = nullptr;
//         this->right = nullptr;
//     }
// };

// class BinaryTree
// {
// public:
//     Node *root;

//     BinaryTree()
//     {
//         root = nullptr;
//     }

//     void addNode(int data)
//     {
//         Node *newNode = new Node(data);

//         if (root == nullptr)
//         {
//             root = newNode;
//         }
//         else
//         {
//             Node *focusNode = root;
//             Node *parent;

//             while (true)
//             {
//                 parent = focusNode;

//                 if (data < focusNode->data)
//                 {
//                     focusNode = focusNode->left;
//                     if (focusNode == nullptr)
//                     {
//                         parent->left = newNode;
//                         return;
//                     }
//                 }
//                 else
//                 {
//                     focusNode = focusNode->right;
//                     if (focusNode == nullptr)
//                     {
//                         parent->right = newNode;
//                         return;
//                     }
//                 }
//             }
//         }
//     }

//     void preOrderTraversal(Node *focusNode)
//     {
//         if (focusNode != nullptr)
//         {
//             std::cout << focusNode->data << " ";
//             preOrderTraversal(focusNode->left);
//             preOrderTraversal(focusNode->right);
//         }
//     }
//     void inOrderTraversal(Node *focusNode)
//     {
//         if (focusNode != nullptr)
//         {
//             inOrderTraversal(focusNode->left);
//             std::cout << focusNode->data << " ";
//             inOrderTraversal(focusNode->right);
//         }
//     }
//     void postOrderTraversal(Node *focusNode)
//     {
//         if (focusNode != nullptr)
//         {
//             postOrderTraversal(focusNode->left);
//             postOrderTraversal(focusNode->right);
//             std::cout << focusNode->data << " ";
//         }
//     }
// };

// int main()
// {
//     BinaryTree tree;

//     tree.addNode(50);
//     tree.addNode(25);
//     tree.addNode(75);
//     tree.addNode(12);
//     tree.addNode(37);
//     tree.addNode(43);
//     tree.addNode(30);

//     tree.preOrderTraversal(tree.root);
//         std::cout << "\n";
//     tree.inOrderTraversal(tree.root);
//         std::cout << "\n";
//     tree.postOrderTraversal(tree.root);
//         std::cout << "\n";


//     return 0;
// }
