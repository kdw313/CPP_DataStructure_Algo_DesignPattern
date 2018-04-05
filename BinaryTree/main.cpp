#include "BinaryTree.h"

void printTree(node *node, int  id)
{
    if(!node)
        return;

    printTree(node->left, id);

    id++;
    std::cout << node->key_value << std::endl;

    printTree(node->right, id);
}

int main(){

    BinaryTree *bt =  new BinaryTree();

    std::cout << "insert 8" << std::endl;
    bt->insert(8);

    std::cout << "insert 5" << std::endl;
    bt->insert(5);

    std::cout << "insert 21" << std::endl;
    bt->insert(21);
    
    std::cout << "insert 4" << std::endl;
    bt->insert(4);

    printTree(bt->root, 0);
}

