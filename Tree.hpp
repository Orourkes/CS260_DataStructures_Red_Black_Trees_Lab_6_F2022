#pragma once
#include <string>

#define black = true;
#define red = false;

class TreeNode
{
private:

    int value;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int value) : value(value), right(nullptr), left(nullptr) {}

    void setLeft(TreeNode* left) { this->left = left; }
    void setRight(TreeNode* right) { this->right = right; }

    char getValue() { return this->value; }
    TreeNode* getLeft() { return this->left; }
    TreeNode* getRight() { return this->right; }

};


class Tree
{
private:
    TreeNode* Root;
    std::string recPreOrder(TreeNode* ptr);
    std::string recPostOrder(TreeNode* ptr);
    std::string recInOrder(TreeNode* ptr);

public:
    Tree() { Root = nullptr; }
    ~Tree();
    void recDelNode(TreeNode*);
    void addChild(TreeNode * parent, int value);
    void insertValue(int value); // – add a new node containing value to the tree
    bool findValue(int value); // – return true if there is a node containing value, false otherwise
    bool removeValue(int value); // – if there is a node in the tree containing value, remove itand return
        //true.If there is not such a node, return false.You should mark it as removed, not actually
        //remove the node.
    std::string preOrder(); // – return a string containing a prefix listing of the tree’s contents.If a node was
        //deleted, add a D to its value.This method must be coded recursively.
    std::string inOrder(); // – return a string containing an infix listing of the tree’s contents.If a node was
        //deleted, add a D to its value.This method must be coded recursively.
    std::string postOrder(); // – return a string containing a postfix listing of the tree’s contents.If a node was
        //deleted, add a D to its value.This method must be coded recursively.

        
        
};

