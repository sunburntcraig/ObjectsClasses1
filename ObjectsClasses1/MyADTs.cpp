//
//  MyADTs.cpp
//  ObjectsClasses1
//
//  Created by Craig Reynolds on 22/04/2024.
//

#include "MyADTs.hpp"
#include <iostream>


//--------ADT simple stack using array

stack::stack(int size)
{
    arr = new int[size];
    topEl=-1;
    stack::size = size;
}

int stack::pop()
{
    if (topEl >= 0 )
        return arr[topEl--];
    else
        return -1;
}

int stack::push(int value)
{
    
    int OK=0;
    
    if (topEl < size-1)
    {
        arr[++topEl] = value;
        OK =1;
    }

    return OK;
}

int stack::top()
{
    return topEl>=0?arr[topEl]:-1;
}

int stack::getSize()
{
    return size;
}

int stack::getCount()
{
    return topEl+1;
}

void stack::print()
{
    std::cout<<"\nStack elements :";
    for (int i = 0; i<= topEl; i++)
        std::cout<<arr[i]<<" ";
}


//--------ADT Stack Using Linked List
llStack::llStack()
{
    
}

llStack::~llStack()
{
    
}

void llStack::push(int value)
{
    theStack.append(value);
}

int llStack::pop()
{
    int retValue = top();
    theStack.clip();
    
    return retValue;
}

bool llStack::pop(int &retValue)
{
    bool success = false;
    
    if (theStack.getSize())
    {
        retValue = top();
        theStack.clip();
        success = true;
    }
    
    return success;
}

int llStack::top()
{
    return theStack.getNthNode(theStack.getSize())->getValue();
}

void llStack::print()
{
    theStack.print();
}

//--------ADT queue using array

queue::queue(int size)
{
    theQueue = new int[size];
    queue::size = size;
    count = 0;
}

queue::~queue()
{
    delete theQueue;
}

int queue::enqueue(int value)
{
    if (count == size)
        return -1;
    
    theQueue[count++] = value;
    
    return 1;
    
}

int queue::dequeue()
{
    int value;
    if (count == 0)
        return -1;
    
    value = theQueue[first];
    shiftLeft();
    
    return value;
}

int queue::front()
{
    return theQueue[first];
}

int queue::length()
{
    return count;
}

void queue::shiftLeft()
{
    for (int i=0; i < count; i++)
        theQueue[i] = theQueue[i+1];
    
    count--;
}

void queue::print()
{
    std::cout<<"\nQueue elements :";
    for (int i = 0; i < count; i++)
        std::cout<<theQueue[i]<<" ";
}


//--------ADT queue using LList

queueL::queueL()
{
    
}

queueL::~queueL()
{
    
}

void queueL::enqueue(int value)
{
    theQueue.append(value);
}

int queueL::dequeue()
{
    int retValue = theQueue.getNthValue(first);
    theQueue.remove(first);
    
    return retValue;
}

int queueL::front()
{
    return theQueue.getNthValue(first);
}

int queueL::length()
{
    return theQueue.getSize();
}

void queueL::print()
{
    theQueue.print();
}

std::ostream &operator<<(std::ostream &output, const queueL &theQ)

{
    output<<theQ.theQueue;
    
    return output;
}







//--------ADT Linked List basics

//--------ADT Node
node::node()
{
    nextNode = NULL;
    value = 0;
}
node::node(node* next, int val)
{
    setNext(next);
    setValue(val);
}

node::~node()
{
    
}

void node::setValue(int val)
{
    value = val;
}

void node::setNext(node* next)
{
    nextNode = next;
}

int node::getValue()
{
    return value;
}

node* node::getNext()
{
    return nextNode;
}

//---- List

lList::lList()
{
    start = last = NULL;
    size = 0;
}

lList::~lList()
{

    while (size-- > 0)
        clip();
}

void lList::append(int val)
{
    node *newnode = new node(NULL,val);
    
    if (start == NULL)
    {
        start = newnode;
        last = start;
    }
    else
    {
        last->setNext(newnode);
        last = last->getNext();
    }
        
    size++;
}

void lList::clip()
{
    node *prior = start;
    
    // List empty, do nothing
    if (start == NULL)
        return;
    
    // only 1 element
    if (start == last)
    {
        delete start;
        start = last = NULL;
    }
    else
    {
        while (prior->getNext() != last)
        {
            prior = prior->getNext();
        }
        delete prior->getNext();
        prior->setNext(NULL);
        last = prior;
    }
    size--;
        
}

int lList::getNthValue(int index)
{
    int counter;
    node *nptr = start;
    
    if (index > size || index == 0)
        return -1;

    for (counter = 1; counter < index; nptr = nptr->getNext(),counter++) ; //empty loop
    
    return nptr->getValue();
}

node *lList::getNthNode(int index)
{
    int counter;
    node *nptr = start;
    
    if (index > size || index == 0)
        return NULL;

    for (counter = 1; counter < index; nptr = nptr->getNext(),counter++) ; //empty loop
    

    return nptr;
}


void lList::remove(int value)
{
    node *toRemove, *prior;
    
    if (value < 1 || value > getSize())
        return;
    
    
    if (value == 1)
    {
        toRemove = start;
        start = start->getNext();
       
    }
    else
    {
        prior = getNthNode(value-1);
        toRemove = prior->getNext();
        prior->setNext(toRemove->getNext());
    }
    
    delete toRemove;
    size--;
}

int lList::getSize() const
{
    return size;
}


void lList::print() const
{
    node *nptr = start;
    std::cout<<"\nList elements :";
    
    while (nptr != NULL)
    {
        std::cout<<nptr->getValue()<<" ";
        nptr = nptr->getNext();
    }
    
    std::cout<<"\nList elements done:";
}

std::ostream &operator<<(std::ostream& output, const lList &theList)
{
    node *nptr = theList.start;
    output<<"\nList elements :";
    
    while (nptr != NULL)
    {
        output<<nptr->getValue()<<" ";
        nptr = nptr->getNext();
    }
    
    return output;
    
}





//--------ADT dynamically created array;

    myArray::myArray (int size)
    {
        list = new int[size];
        myArray::size = size;
        endEl = 0;
    }

    myArray::~myArray()
    {
        delete list;
    }

    void myArray::clear()
    {
        for (int i = 0; i< size; i++)
            addElement(0);
    }


    int myArray::findElement(int toFind)
    {
        int found = -1;
        
        for (int i = 0; i < endEl; i++)
            if (list[i] == toFind)
                found = i+1;
        
        return found;
    }

    int myArray::getElement(int atIndex)
    {
        int found;
        
        if (atIndex < 1 || atIndex > getCount() )
            found = -1;
        else
            found = list[atIndex-1];
           
        return found;
    }

    int myArray::addElement(int newEl)
    {
        if ( endEl == getSize() )
            return 0;
        
        list[endEl++] = newEl;
        return endEl;
    }

    int myArray::deleteElement(int delEl)
    {
        int deleted =0;
        int loc = findElement(delEl);
        
        if (loc != -1)
        {
            for (int i = loc-1; i < endEl; i++ )
                list[i] = list[i+1];
            
            endEl--;
            deleted = 1;
        }
        
        return deleted;
    }

    int myArray::isEquals(myArray compareList)
    {
        
        if (getSize() != compareList.getSize())
             return 0;
        
        int equal = 1;
        for (int i = 0; i < getSize()-1; i++)
            if (getElement(i) != compareList.getElement(i))
                equal = 0;
                
        return equal;
    }
                
    void myArray::print() const
    {
        for (int i= 0; i<endEl; i++)
         std::cout<<" "<<list[i];
    }

    int myArray::getSize()
    {
        return size;
    }

    int myArray::getCount()
    {
        return endEl;
    }


// ------------ Binary Tree
// --------- BTNode


btNode::btNode( int newData, btNode* leftNode, btNode* rightNode)
{
    data = newData;
    nextLeftNode = leftNode;
    nextRightNode = rightNode;
}

btNode::~btNode()
{
    //std::cout<<"\ndel:"<<data;
}


void btNode::setData(const int newData)
{
    data = newData;
}


int btNode::getData()
{
    return data;
}


btNode* btNode::getLeft()
{
    return nextLeftNode;
}


btNode* btNode::getRight()
{
    return nextRightNode;
}


void btNode::setLeft(btNode* nextNode)
{
    nextLeftNode = nextNode;
}


void btNode::setRight(btNode* nextNode)
{
    nextRightNode = nextNode;
}


bool btNode::operator>(const int newData) const
{
    return (data > newData);
}


bool btNode::operator<(const int newData) const
{
    return (data > newData);
}


bool btNode::operator==(const int newData)const
{
    return (data == newData);
    
}





// --------- Binary Tree


binaryTree::binaryTree() :root(NULL), count(0)
{
    
}

binaryTree::~binaryTree()
{
    if (root == NULL)
        return;
    
    btNode *leftTree = root->getLeft(),
            *rightTree = root->getRight();
    
    deleteSubTree(leftTree);
    deleteSubTree(rightTree);
    delete root;

}

bool binaryTree::insertData(const int newData)
{
    return insertHelp(newData, root);
}

/* btNode *left =NULL; btNode *right = NULL;
 
 if (thisNode == NULL)
 {
     btNode *newNode = new btNode(newData);
     thisNode = newNode;
 }
 else
 {
     int thisData = thisNode->getData();
     if ( thisData == newData)
         return false;           //do nothing, already in tree
     else if ( thisData > newData)
     {
         left = thisNode->getLeft();
         insertHelp(thisData, left);
         thisNode->setLeft(left);
     }
     else
     {
         right = thisNode->getRight();
         insertHelp(thisData, right);
         thisNode->setRight(right);
     }
 }
 
 return true;
*/

bool binaryTree::insertHelp(const int newData, btNode* &thisNode)
{
   
    
    if (thisNode == NULL)
    {
        btNode *newNode = new btNode(newData);
        thisNode = newNode;
        return true;
    }
    
    btNode *Node = NULL, *nextLeft, *nextRight;
    int thisData = thisNode->getData();
    Node = thisNode;
    nextLeft = thisNode->getLeft();
    nextRight = thisNode->getRight();
    
    while (Node!= NULL )
    {
        if (thisData == newData)
             return false;
        else
            if (newData > thisData)
            {
                if (nextRight != NULL)
                {
                    Node =  Node->getRight();
                    thisData =  Node->getData();
                    nextLeft =  Node->getLeft();
                    nextRight = Node->getRight();
                }
                else
                {   Node->setRight(new btNode(newData));
                    count++;
                    return true;
                }
            }
            else  //newData < thisData
            {
                if (nextLeft != NULL)
                {
                    Node =  Node->getLeft();
                    thisData =  Node->getData();
                    nextLeft =  Node->getLeft();
                    nextRight = Node->getRight();
                }
                else
                {
                    Node->setLeft(new btNode(newData));
                    count++;
                    return true;
                }
                    
                    
            } //else  newData < thisData
    } // while
    
    return false;
}

bool binaryTree::deleteData(const int delData)
{
    //Base case root node is one to delete
    btNode *nextLeft, *nextRight;
    int thisData = root->getData();
    
    if (thisData == delData)
    {
        llStack tempStack;
        int stackTop;
        
        nextLeft = root->getLeft();
        nextRight = root->getRight();
        extractSubTree(nextLeft, tempStack);
        extractSubTree(nextRight, tempStack);
        
        delete root;
        root = NULL;
        
        while (tempStack.pop(stackTop))
            insertData(stackTop);
        
        return true;
    }
    
    if (delData < thisData)
        return deleteHelper(delData, root, root->getLeft(), left);
    else
        return deleteHelper(delData,root, root->getRight(), right);
}

// iterative deleteHelper

bool binaryTree::deleteHelp(const int delData,btNode* prior, btNode* thisNode, flag lr)
{
    bool found = false;
    
    if (thisNode == NULL)
        return found;
    
    btNode *Node = NULL, *nextLeft, *nextRight;
    int thisData, stackTop;
    llStack tempStack;
    
    Node = thisNode;
    
    while ( Node!=NULL )
    {
        thisData = Node->getData();
        nextLeft = Node->getLeft();
        nextRight = Node->getRight();
        
        if (thisData == delData)
        {
            found = true;
            extractSubTree(nextLeft, tempStack);
            extractSubTree(nextRight, tempStack);
            
            // turn this to a leaf node and re-insert subtree elements
            Node->setLeft(NULL);
            Node->setRight(NULL);
            
           if (tempStack.pop(stackTop))
           {
               Node->setData(stackTop);
               
               while (tempStack.pop(stackTop))
                   insertData(stackTop);
           }
           else // empty subtrees;
           {
               delete Node;
               Node = NULL;
               if (lr == left)
                   prior->setLeft(NULL);
               else
                   prior->setRight(NULL);
           }
            
            count--;
        } // thisData == delData
        else
        {
            prior = Node;
            
            if (delData > thisData)
            {
                Node = Node->getRight();
                lr = right;
            }
            else
            {
                Node = Node->getLeft();
                lr = left;
            }
        }
    }
        
   return found;
}

// ------recursive deletehelp

bool binaryTree::deleteHelper(const int delData,btNode* prior, btNode* thisNode, flag lr)
{
    bool found = false;
    
    if (thisNode == NULL)
        return found;
    
    btNode *Node = NULL, *nextLeft, *nextRight;
    int thisData, stackTop;
    llStack tempStack;
    
    Node = thisNode;
    thisData = Node->getData();
    nextLeft = Node->getLeft();
    nextRight = Node->getRight();
        
    if (thisData == delData)
    {
        found = true;
        extractSubTree(nextLeft, tempStack);
        extractSubTree(nextRight, tempStack);
            
        // turn this to a leaf node and re-insert subtree elements
        Node->setLeft(NULL);
        Node->setRight(NULL);
            
        if (tempStack.pop(stackTop))
           {
               Node->setData(stackTop);
               
               while (tempStack.pop(stackTop))
                   insertData(stackTop);
           }
        else // empty subtrees;
           {
               delete Node;
               Node = NULL;
               if (lr == left)
                   prior->setLeft(NULL);
               else
                   prior->setRight(NULL);
           }
            
            count--;
       
    }
    else
        if (delData < thisData)
            found = deleteHelper(delData,Node, Node->getLeft(), left);
        else
            found = deleteHelper(delData,Node, Node->getRight(), right);
        
   return found;
}

void binaryTree::extractSubTree(btNode* thisNode, llStack &theStack)
{
    if (thisNode == NULL)
        return;
    
    extractSubTree(thisNode->getLeft(), theStack);
    extractSubTree(thisNode->getRight(), theStack);
    theStack.push(thisNode->getData());
    delete thisNode;
}

void binaryTree::deleteSubTree(btNode* thisNode)
{
    if (thisNode == NULL)
        return;
    
    deleteSubTree(thisNode->getLeft());
    deleteSubTree(thisNode->getRight());
    delete thisNode;

}


void binaryTree::print(const traverse order)
{
    
    switch (order) {
        case PreOrder:
            std::cout<<"\nPre Order :";
            printPreOrder(root);
            break;
        case InOrder:
            std::cout<<"\nIn Order :";
            printInOrder(root);
            break;
        case PostOrder:
            std::cout<<"\nPost Order :";
            printPostOrder(root);
            break;
        default:
            break;
    }
}

void binaryTree::printPreOrder( btNode* thisNode) const
{
    if (thisNode == NULL)
        return;
    
    std::cout<<" "<<thisNode->getData();
    printPreOrder(thisNode->getLeft());
    printPreOrder(thisNode->getRight());

}

void binaryTree::printInOrder( btNode* thisNode) const
{
    if (thisNode == NULL)
        return;
        
    printInOrder(thisNode->getLeft());
    std::cout<<" "<<thisNode->getData();
    printInOrder(thisNode->getRight());

}

void binaryTree::printPostOrder( btNode* thisNode) const
{
    if (thisNode == NULL)
        return;
    
    printPostOrder(thisNode->getLeft());
    printPostOrder(thisNode->getRight());
    std::cout<<" "<<thisNode->getData();

}

bool binaryTree::traversePre()
{
    
    return true;
}
bool binaryTree::traverseIn()
{
    return true;

}
bool binaryTree::traversePost()
{
    return true;

}




