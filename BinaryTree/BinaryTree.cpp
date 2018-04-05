#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    BinaryTree::root = nullptr;
}

void BinaryTree::destroy_tree(node *leaf)
{

    if(leaf != nullptr){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }

    return;
}

void BinaryTree::insert(int key, node *leaf)
{

    // if inserting key is less than node
    if(key < leaf -> key_value)
    {
        // if the left node is not empty
        if(leaf->left != nullptr)
        {
            insert(key, leaf->left);
        }
        // other wise
        else 
        {
            // creates a new node and assign the key value
            leaf->left = new node;
            leaf->left->key_value = key;

            //sets the left and right of new node to be null  
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    // if its larger
    else if ( key >= leaf -> key_value)
    {
        // if the right node is not empty
        if (leaf->right != nullptr)
        {
            insert(key, leaf->right);
        }
        else
        {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
    else
    {
        std::cout << "there is already duplicated value" << std::endl;
    }
}

node *BinaryTree::search(int key, node *leaf)
{
    if (leaf != nullptr)
    {
        if(key == leaf -> key_value)
        {
            return leaf;
        }
        
        if(key<leaf->key_value)
        {
            return search(key, leaf->left);
        }
        else 
        {
            return search(key, leaf->right);
        }
    }
    else
    {
        return nullptr;
    }
}

void BinaryTree::insert(int key)
{
    if (root!=nullptr)
    {
        insert(key, root);
    }
    else
    {
        root = new node;
        root->key_value = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

node *BinaryTree::search(int key)
{
    return search(key, root);
}

void BinaryTree::destroy_tree()
{
    destroy_tree(root);
}
