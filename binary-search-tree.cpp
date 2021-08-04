#include "binary-search-tree.h"
#include <iostream>
#include <queue>

typedef BinarySearchTree::DataType DataType;
typedef BinarySearchTree::Node Node;

using namespace std;
unsigned int depthHelper(Node* node);

BinarySearchTree::Node::Node(DataType newval)
{
    val = newval;  // Value of the node.
    left = nullptr;    // Pointer to the left node.
    right = nullptr;   // Pointer to the right node.
}

int BinarySearchTree::getNodeDepth(Node* n) const
{

}

BinarySearchTree::BinarySearchTree()
{
    root_ = nullptr;
    size_ = 0;
}

void destroy(Node* node) // Helper function for destructor
{
    if(node != nullptr)
    {
        if(node->left != nullptr){
            destroy(node->left);
        }
        if(node->right != nullptr){
            destroy(node->right);
        }

        delete node;
    }
}

BinarySearchTree::~BinarySearchTree()
{
    destroy(root_);
}

unsigned int BinarySearchTree::size() const
{
    return size_;
}

DataType BinarySearchTree::max() const
{
    Node* currentNode = root_;
    while(currentNode->right != nullptr)
    {
        currentNode = currentNode->right;
    }
    return currentNode->val;
}

DataType BinarySearchTree::min() const
{
    Node* currentNode = root_;
    while(currentNode->left != nullptr)
    {
        currentNode = currentNode->left;
    }
    return currentNode->val;
}

unsigned int BinarySearchTree::depth() const
{
    return depthHelper(root_) - 1;
}

unsigned int depthHelper(Node* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    else
    {
        unsigned int lD = depthHelper(node->left);
        unsigned int rD = depthHelper(node->right);

        if (lD > rD)
        {
            return (lD + 1);
        }
        else
        {
            return (rD + 1);
        }
    }
}

void BinarySearchTree::print() const
{

}

bool BinarySearchTree::exists(DataType val) const
{
    Node* currentNode = root_;
    while(currentNode != nullptr)
    {
        if (val == currentNode-> val){
            return true;
        }
        else if(val > currentNode->val)
        {
            currentNode = currentNode-> right;
        }
        else
        {
            currentNode = currentNode-> left;
        }
    }
    return false;
}

Node* BinarySearchTree::getRootNode()
{
    return root_;
}

Node** BinarySearchTree::getRootNodeAddress()
{
    return &root_;
}

bool BinarySearchTree::insert(DataType val)
{
    if(exists(val))
    {
        return false;
    }

    if(size_==0)
    {
        root_ = new Node(val);
        size_++;
        return true;
    }

    Node* currentNode = root_;
    Node* previousNode= nullptr;
    while(currentNode != nullptr) { // Finds location to insert
        if(val > currentNode->val)
        {
            previousNode = currentNode;
            currentNode = currentNode-> right;
        }
        else
        {
            previousNode = currentNode;
            currentNode = currentNode-> left;
        }
    }
    if(val > previousNode->val)
    {
        previousNode->right = new Node(val);
    }
    else{
        previousNode->left = new Node(val);
    }

    size_++;
    return true;
}

Node* findPredecessor(Node* ptr) {
}

bool BinarySearchTree::remove(DataType val)
{
    Node* currentNode = root_;
    Node* previousNode = nullptr;

    // Find currentNode with given value
    while(currentNode != nullptr && val != currentNode->val) { // Locates node to be removed
        if (val > currentNode->val)
        {
            previousNode = currentNode;
            currentNode = currentNode->right;
        }
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->left;
        }
    }
    if (currentNode == nullptr) {
        // We didn't find the node
        return false;
    }


    // Assuming we did find the node:

    // If currentNode has zero or one child
    if (currentNode->left == nullptr || currentNode->right == nullptr)
    {
        if (previousNode == nullptr) // If only one node is left
        {
            root_ = nullptr;
        }
        else if (currentNode->left != nullptr) {
            if (previousNode->left == currentNode)
            {
                previousNode->left = currentNode->left;
            }
            else
            {
                previousNode->right = currentNode->left;
            }
        }
        else
        {
            if (previousNode->left == currentNode)
            {
                previousNode->left = currentNode->right;
            }
            else
            {
                previousNode->right = currentNode->right;
            }
        }
        delete currentNode;
    }
    else
    {
        // Current node has two children
        Node* toBeRemoved = currentNode;
        previousNode = currentNode;
        currentNode = currentNode->left;
        while(currentNode->right != nullptr)
        {
            previousNode = currentNode;
            currentNode = currentNode->right;
        }

        if (previousNode->left == currentNode)
        {
            previousNode->left = currentNode->left;
        }
        if (previousNode->right == currentNode)
        {
            previousNode->right = currentNode->left;
        }
        toBeRemoved->val = currentNode->val;
        delete currentNode;
    }

    size_--;
    return true;
}
