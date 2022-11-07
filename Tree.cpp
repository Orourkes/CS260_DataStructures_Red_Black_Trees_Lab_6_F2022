#include "Tree.hpp"


Tree::~Tree()
{
    recDelNode(Root);
}
void Tree::addChild(TreeNode* parent, int value)
{
    TreeNode* newChild = new TreeNode(value);
    if (value >= parent->getValue())
    {
        if (parent->getRight() != nullptr)
            addChild(parent->getRight(), value);
        parent->setRight(newChild);
    }
    else
    {
        if (parent->getLeft() != nullptr)
            addChild(parent->getLeft(), value);
        parent->setLeft(newChild);
    }
}
/****************
* – add a new node containing value to the tree
* ******************/
void Tree::insertValue(int value)
{
    TreeNode* newChild= new TreeNode(value); 
    if (Root == nullptr)
        Root = newChild;
    else
        addChild(Root, value);
}
/****************
* – return true if there is a node containing value, false otherwise
* ******************/
bool Tree::findValue(int value)
{
    return true;
}

/****************
* – if there is a node in the tree containing value, remove itand return
* true.If there is not such a node, return false.You should mark it as removed, not actually
* remove the node.
* ******************/
bool Tree::removeValue(int value)
{
    return true;
}

void Tree::recDelNode(TreeNode* delNode)
{
    if (delNode != nullptr)
    {
        recDelNode(delNode->getLeft());
        recDelNode(delNode->getRight());
        delete delNode;
    }
}

/****************
* – return a string containing a prefix listing of the tree’s contents.If a node was
* deleted, add a D to its value.This method must be coded recursively.
*******************/
std::string Tree::preOrder()
{
    return recPreOrder(Root);
}

/****************
* – return a string containing an infix listing of the tree’s contents.If a node was
*   deleted, add a D to its value.This method must be coded recursively.
*******************/
std::string Tree::inOrder()
{
    return recInOrder(Root);
}

/****************
* return a string containing a postfix listing of the tree’s contents.If a node was
* deleted, add a D to its value.This method must be coded recursively.
******************/
std::string Tree::postOrder()
{
    return recPostOrder(Root);

}
std::string Tree::recPreOrder(TreeNode* ptr)
{
    if (ptr != nullptr)
    {
        std::string buffer = "";

        buffer += ptr->getValue();
        buffer += recInOrder(ptr->getLeft());
        buffer += recInOrder(ptr->getRight());

        return buffer;
    }
    return "";
}
std::string Tree::recPostOrder(TreeNode* ptr)
{
    if (ptr != nullptr)
    {
        std::string buffer = "";

        buffer += recInOrder(ptr->getLeft());
        buffer += recInOrder(ptr->getRight());
        buffer += ptr->getValue();

        return buffer;
    }
    return "";
}
std::string Tree::recInOrder(TreeNode* ptr)
{
    if (ptr != nullptr)
    {
        std::string buffer = "";

        buffer += recInOrder(ptr->getLeft());
        buffer += ptr->getValue();
        buffer += recInOrder(ptr->getRight());

        return buffer;
    }
    return "";
}