#include "Tree.hpp"


Tree::~Tree()
{
    recDelNode(Root);
}

void Tree::addChild(TreeNode* parent, int value)
{//find previously deactivated node, reactivate it.
    TreeNode* findNode = recFindValue(Root, value, false);
    if (findNode != nullptr && !findNode->getIsActive())
    {
        reactivate(findNode);
        return;
    }
    TreeNode* newChild = new TreeNode(value);
    if (value >= parent->getValue())
    {
        if (parent->getRight() == nullptr)
        {
            parent->setRight(newChild);
        }
        else if (parent->getRight() != nullptr)
        {
            addChild(parent->getRight(), value);
        }
    }
    else
    {
        if (parent->getLeft() == nullptr)
        {
            parent->setLeft(newChild);
        }
        else if (parent->getLeft() != nullptr)
        {
            addChild(parent->getLeft(), value);
        }
        
    }
}

void Tree::reactivate(TreeNode* reAct)
{
    reAct->activate();
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
    TreeNode* findNode = recFindValue(Root, value, false);
    return (findNode!= nullptr && findNode->getIsActive());
}

TreeNode* Tree::recFindValue(TreeNode* parent, int value, bool found)
{
    if (parent != nullptr)
    {
        if (parent->getValue() == value)
            return parent;
        else if (parent->getValue() > value)
            return recFindValue(parent->getLeft(), value, false);
        else
            return recFindValue(parent->getRight(), value, false);
    }
    return nullptr;
}

/****************
* – if there is a node in the tree containing value, remove itand return
* true.If there is not such a node, return false.You should mark it as removed, not actually
* remove the node.
* ******************/
bool Tree::removeValue(int value)
{
    TreeNode* findNode = recFindValue(Root, value, false);
    if (findNode != nullptr && findNode->getIsActive()) 
    {
        findNode->deactivate();
        return true;
    }

    return false;
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
        if(ptr->getIsActive())
        {
            buffer += std::to_string(ptr->getValue());
            buffer += " ";
        }
        else
        {
            buffer += std::to_string(ptr->getValue());
            buffer += "D ";
        }
        buffer += recPreOrder(ptr->getLeft());
        buffer += recPreOrder(ptr->getRight());

        return buffer;
    }
    return "";
}

std::string Tree::recPostOrder(TreeNode* ptr)
{
    if (ptr != nullptr)
    {
        std::string buffer = "";

        buffer += recPostOrder(ptr->getLeft());
        buffer += recPostOrder(ptr->getRight());
        if (ptr->getIsActive())
        {
            buffer += std::to_string(ptr->getValue());
            buffer += " ";
        }
        else
        {
            buffer += std::to_string(ptr->getValue());
            buffer += "D ";
        }
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
        if (ptr->getIsActive())
        {
            buffer += std::to_string(ptr->getValue());
            buffer += " ";
        }
        else
        {
            buffer += std::to_string(ptr->getValue());
            buffer += "D ";
        }
        buffer += recInOrder(ptr->getRight());
        
        return buffer;
    }
    return "";
}

void Tree::display()
{
    //std::cout << std::to_string(Root->getValue()) << std::endl;
    recDisplay(Root);
}

void Tree::recDisplay(TreeNode* p)
{
    if(p != nullptr)
    std::cout << std::to_string(p->getValue()) << std::endl;
    if (p->getLeft() != nullptr)
        recDisplay(p->getLeft());
    if (p->getRight() != nullptr)
        recDisplay(p->getRight());
}
int Tree::findLarger(int value)
{
    TreeNode* findNode = recFindValue(Root, value, false);
    if (findNode != nullptr && findNode->getIsActive())
    {
        return findNode->getValue();
    }

    return recFindLargerValue(Root, value, -1, false);
}
int Tree::recFindLargerValue(TreeNode* parent, int value, int currentLarger, bool found)
{
    if (parent != nullptr)
    {
          
        if (parent->getValue() > value)
        {
            if (currentLarger == -1)
                currentLarger = parent->getValue();
            else if (currentLarger > parent->getValue())
                currentLarger = parent->getValue();
            else if (currentLarger < parent->getValue())
                return recFindLargerValue(parent->getRight(), value, currentLarger, false);
                //return currentLarger;
            return recFindLargerValue(parent->getLeft(), value, currentLarger, false);
        }
        else
        {
            if (currentLarger > parent->getValue())
                return recFindLargerValue(parent->getRight(), value, currentLarger, false);
            //if(currentLarger > parent->getValue())
             //   return recFindLargerValue(parent->getLeft(), value, currentLarger, false);
            if (currentLarger == -1)
                return recFindLargerValue(parent->getRight(), value, currentLarger, false);
        }

    }
    return currentLarger;
}
int Tree::removeLarger(int value)
{
    TreeNode* findNode = recFindValue(Root, value, false);
    if (findNode != nullptr && findNode->getIsActive())
    {
        return findNode->getValue();
    }

    int tempRetInt = recFindLargerValue(Root, value, -1, false);
    removeValue(tempRetInt);
    return tempRetInt;
}