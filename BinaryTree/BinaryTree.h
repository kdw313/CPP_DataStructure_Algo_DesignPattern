#pragma once

#include <iomanip>
#include <iostream>
#include "node.h"

class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(int key);
        void destroy_tree();
        node *search(int key);
        
        node *root;

      private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);

};
