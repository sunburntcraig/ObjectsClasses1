//
//  MyADTs.hpp
//  ObjectsClasses1
//
//  Created by Craig Reynolds on 22/04/2024.
//

#ifndef MyADTs_hpp
#define MyADTs_hpp

#include <stdio.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <iostream>

// ----------- Array based stack
class stack{
    
public:
    stack(int);
    int pop();
    int push(int);
    int top();
    int getSize();
    int getCount();
    void print();
private:
    int *arr;
    int topEl;
    int size;
};

// ------------ Linked list

class node {
    
public:
    node();
    node(node*, int);
    ~node();
    void setValue(int);
    int getValue();
    void setNext(node*);
    node* getNext();
 private:
    node *nextNode;
    int value;
};

class lList {
    
    friend std::ostream &operator<<(std::ostream&, const lList &);
    
public:
    lList();
    ~lList();
    void append(int);
    void clip();
    int getNthValue(int);
    node *getNthNode(int);
    void remove(int);
    int getSize() const;
    void print() const;

private:
    node *start, *last;
    int size;
};


// ------------ Stack using LL

class llStack {
public:
    llStack();
    ~llStack();
    void push(int);
    int pop();
    bool pop(int &);
    int top();
    void print();
    
private:
    lList theStack;
    
};


// ------------ Queue using array

class queue {
public:
    queue(int);
    ~queue();
    int enqueue(int);
    int dequeue();
    int front();
    int length();
    void print();
    
private:
    void shiftLeft();
    int *theQueue;
    int size;
    int count;
    const int first =0;
    
};

// ------------ Queue using LList

class queueL {
    
    friend std::ostream &operator<<(std::ostream &, const queueL &);
    
public:
    queueL();
    ~queueL();
    void enqueue(int);
    int dequeue();
    int front() ;
    int length();
    void print();
    
private:
    lList theQueue;
    const int first =1;
};


// ------------ array with bounds checking
class myArray {
    
public:
    myArray(int);
    ~myArray();
    void clear();
    int findElement(int);
    int getElement(int);
    int addElement(int);
    int deleteElement(int);
    int isEquals(myArray compareList);
    void print() const;
    int getSize();
    int getCount();
    
private:
    // start subscript = 1, end subscript = array size.
    int endEl, size;
    int *list;
    
};

// ------------ Binary Tree

class btNode {
    
public:
    btNode( int = 0, btNode* = nullptr, btNode* = nullptr);
    ~btNode();
    void setData(const int newData);
    int getData();
    btNode* getLeft();
    btNode* getRight();
    void setLeft(btNode*);
    void setRight(btNode*);
    bool operator>(const int newData) const;
    bool operator<(const int newData) const;
    bool operator==(const int newData)const;
    
private:
    btNode * nextLeftNode;
    btNode * nextRightNode;
    int data;
};

class binaryTree {
    
public:
    binaryTree();
    ~binaryTree();
    bool insertData(const int newData);
    bool deleteData(const int delData);
    bool traversePre();
    bool traverseIn();
    bool traversePost();
    bool isEmpty() { return (root == nullptr);};
    enum traverse { PreOrder, InOrder, PostOrder};
    void print(const traverse);
    const btNode * find(const int target);
    void breadthFirstTraversal();
    
private:
    enum flag {left,right};
    bool insertHelp(const int, btNode* &);
    bool deleteHelp(const int ,btNode* , btNode*, flag);
    bool deleteHelper(const int ,btNode* , btNode*, flag);
    void printPreOrder( btNode* ) const;
    void printInOrder( btNode* ) const;
    void printPostOrder( btNode* ) const;
    void extractSubTree(btNode* , llStack &);
    void deleteSubTree(btNode* );
    const btNode *findHelper( btNode*, const int );

    
    btNode *root;
    int count; 
};



//-------Alternative BT, recursive definition

enum traverseOrder { PreOrder = 0, InOrder, PostOrder};

template <class NodeKey>
class BTAlternative {

protected:
    NodeKey* key;
    BTAlternative<NodeKey>* left;
    BTAlternative<NodeKey>* right;
    int height;
    void Purge();
    
public:
    BTAlternative() : key(nullptr), left(nullptr), right(nullptr), height(0) {};
    BTAlternative(NodeKey&);
  //  BTAlternative(BTAlternative<NodeKey>& other) : key(other.key), left(other.left), right(other.right), height(0) {} ;
    ~BTAlternative();
    
    NodeKey& Key() ;
    BTAlternative& LeftTree() const;
    BTAlternative& RightTree() const;
    // --- Utility methods
    virtual void attachKey(NodeKey&);
    virtual NodeKey& detachKey();
    virtual void attachLeft(BTAlternative&);
    virtual void attachRight(BTAlternative&);
    virtual void detachLeft(BTAlternative&);
    virtual void detachRight(BTAlternative&);
    bool isEmpty() {return key == nullptr;};
    bool isLeaf();
    
    // --- traversal methods
    void breadthFirstTraverse();
    void breadthFirstTraverseAlt();
    void depthFirstTraverse(const traverseOrder);


};



// -------- BT Alternative
template <class NodeKey>
BTAlternative<NodeKey>::BTAlternative(NodeKey& newKey)
{
    
    key = new int{newKey};
    left = new BTAlternative<NodeKey>();
    right = new BTAlternative<NodeKey>();
};

template <class NodeKey>
BTAlternative<NodeKey>::~BTAlternative()
{
    Purge();
}

template <class NodeKey>
void BTAlternative<NodeKey>::Purge()
{
    if (!isEmpty())
    {
        delete key;
        delete left;
        delete right;
        
        key = nullptr;
        left = right = nullptr;
    }
    
}

template <class NodeKey>
NodeKey& BTAlternative<NodeKey>::Key()
{
    if (isEmpty())
        throw std::domain_error("Invalid key access operation");
    
    return *key;
}

template <class NodeKey>
 void BTAlternative<NodeKey>::attachKey(NodeKey& d)
{
    if (!isEmpty())
        throw std::domain_error("Invalid attach operation");
    
    key = &d;
    
    left = new BTAlternative();
    right = new BTAlternative();

}

template <class NodeKey>
bool BTAlternative<NodeKey>::isLeaf()
{
    
    if (key == nullptr)
        throw std::domain_error("Invalid Leaf operation");
    
    return (left->isEmpty() && right->isEmpty()) ;
}

template <class NodeKey>
NodeKey& BTAlternative<NodeKey>::detachKey()
{
    if (!isLeaf())
        throw std::domain_error("Invalid detach operation");
    
    NodeKey& retKey = *key;
    key = nullptr;
    
    delete left;
    delete right;
    return retKey;
}

template <class NodeKey>
void BTAlternative<NodeKey>::depthFirstTraverse(const traverseOrder order)
{
    
    if (isEmpty())
      return;
   
    if (order == PreOrder)
    {
        std::cout<<" "<<*key;
        left->depthFirstTraverse(order);
        right->depthFirstTraverse(order);
    }
    
    if (order == InOrder)
    {
        left->depthFirstTraverse(order);
        std::cout<<" "<<*key;
        right->depthFirstTraverse(order);
    }
    
    if (order == PostOrder)
    {
        right->depthFirstTraverse(order);
        left->depthFirstTraverse(order);
        std::cout<<" "<<*key;
    }
    
}

template <class NodeKey>
void BTAlternative<NodeKey>::breadthFirstTraverse()
{
   
    std::queue<BTAlternative<NodeKey>> theQ;
    // BTAlternative<NodeKey> BTnode(dynamic_cast<BTAlternative<NodeKey>&>(*this));
    //BTAlternative<NodeKey>* leftN;
    //BTAlternative<NodeKey>* rightN;
    
    theQ.push(*this);
    
    while (!theQ.empty())
    {
        std::cout<<theQ.front().Key();
        
        theQ.push(*(theQ.front().left));
        theQ.push(*(theQ.front().right));
        
        theQ.pop();
        
      /*
        leftN = new BTAlternative<NodeKey>(dynamic_cast<BTAlternative<NodeKey>&>( *(theQ.front().left)));
      
        theQ.push( *leftN );
   
        rightN = new BTAlternative<NodeKey>(dynamic_cast<BTAlternative<NodeKey>&>( *(theQ.front().right)));
 
        theQ.push( *rightN );
     
        theQ.pop();

       */
    }
  
}

template <class NodeKey>
void BTAlternative<NodeKey>::breadthFirstTraverseAlt()
{
    /* Horrible hack to because my elegant solution above gets
       stymied by the fact that stl queue pop() function deletes
      the element being popped and I was pushing the tree nodes themselves*/
    
    struct tempNode{
        NodeKey* key;
        BTAlternative<NodeKey> *left;
        BTAlternative<NodeKey> *right;
    }* tnode;
    std::queue<tempNode*> theQ;
     
    tnode = new tempNode;
    tnode->key = key;
    tnode->left = left;
    tnode->right = right;
    
    theQ.push(tnode);
    
    while (!theQ.empty())
    {
        std::cout<<"Key :"<<*(theQ.front()->key)<<" ";
  
        
        tnode = new tempNode;
        tnode->key = theQ.front()->left->key;
        tnode->left = theQ.front()->left->left;;
        tnode->right = theQ.front()->left->right;
        
        if ( !(tnode->key == nullptr) )
            theQ.push(tnode);
        
        tnode = new tempNode;
        tnode->key = theQ.front()->right->key;
        tnode->left = theQ.front()->right->left;;
        tnode->right = theQ.front()->right->right;
        
        if ( !(tnode->key==nullptr) )
            theQ.push(tnode);
     
        theQ.pop();

       
    }
  
}

template <class NodeKey>
void BTAlternative<NodeKey>::attachLeft(BTAlternative& BT)
{
    if (isEmpty())
        throw std::domain_error("Invalid insertion operation");
    
    if (left->isEmpty())
        *left = BT;
}

template <class NodeKey>
void BTAlternative<NodeKey>::attachRight(BTAlternative& BT)
{
    if (isEmpty())
        throw std::domain_error("Invalid insertion operation");
    
    if (right->isEmpty())
        right = &BT;
}

template <class NodeKey>
void BTAlternative<NodeKey>::detachLeft(BTAlternative&)
{
    
}
template <class NodeKey>
void BTAlternative<NodeKey>::detachRight(BTAlternative&)
{
    
}


// Binary Search Tree derived from Binary Tree

template <class NodeKey>
class BSearchT : public BTAlternative<NodeKey>
{
public:
    BSearchT():BTAlternative<NodeKey>(){};
    BSearchT(NodeKey&);
    ~BSearchT();
    virtual void attachKey(NodeKey&);
    virtual NodeKey& detachKey();
    BSearchT& getLeft() const;
    BSearchT& getRight() const;
    NodeKey findMin();
    NodeKey findMax();
    void remove(NodeKey&);
    
protected:
    void Balance();
};

template <class NodeKey>
BSearchT<NodeKey>::BSearchT(NodeKey& d) : BTAlternative<NodeKey>(d)
{
    delete BSearchT<NodeKey>::left;
    delete BSearchT<NodeKey>::right;
    
    BSearchT<NodeKey>::left = new BSearchT();
    BSearchT<NodeKey>::right = new BSearchT();

};

template <class NodeKey>
BSearchT<NodeKey>::~BSearchT()
{
    BSearchT<NodeKey>::Purge();

}

template <class NodeKey>
NodeKey BSearchT<NodeKey>::findMin()
{
    if (  BSearchT<NodeKey>::isEmpty() )
        throw std::domain_error("Emptry Tree");
    else
        if ( getLeft().isEmpty() )
            return *BSearchT<NodeKey>::key;
        else
            return getLeft().findMin();
}

template <class NodeKey>
NodeKey BSearchT<NodeKey>::findMax()
{
    if (  BSearchT<NodeKey>::isEmpty() )
        throw std::domain_error("Emptry Tree");
    else
        if ( getRight().isEmpty() )
            return *BSearchT<NodeKey>::key;
        else
            return getRight().findMax();
}

template <class NodeKey>
BSearchT<NodeKey>& BSearchT<NodeKey>::getLeft() const
{
    return dynamic_cast<BSearchT<NodeKey>&>(*BSearchT<NodeKey>::left) ;
}

template <class NodeKey>
BSearchT<NodeKey>& BSearchT<NodeKey>::getRight() const
{
    return dynamic_cast<BSearchT<NodeKey>&>(*BSearchT<NodeKey>::right) ;
}

template <class NodeKey>
void BSearchT<NodeKey>::attachKey(NodeKey & d)
{
    if ( BSearchT<NodeKey>::isEmpty() )
    {
        BSearchT<NodeKey>::key = new NodeKey(d); 
        BSearchT<NodeKey>::left = new BSearchT();
        BSearchT<NodeKey>::right = new BSearchT();
        return;
    }
    
    if (d == *BSearchT<NodeKey>::key)
        return; // no duplicates
    
    if (d < *BSearchT<NodeKey>::key)
        BSearchT<NodeKey>::left->attachKey(d);
    else
        BSearchT<NodeKey>::right->attachKey(d);
        
}

template <class NodeKey>
NodeKey& BSearchT<NodeKey>::detachKey()
{
    return BTAlternative<NodeKey>::detachKey();
}

template <class NodeKey>
void BSearchT<NodeKey>::remove(NodeKey & d)
{
    if ( BSearchT<NodeKey>::isEmpty() )
        throw std::domain_error("Key Not Found");
    
    NodeKey diff = d - *BSearchT<NodeKey>::key;
    
   if (diff == 0)
    {
            if ( !BSearchT<NodeKey>::getLeft().isEmpty() )
            {
                NodeKey max = BSearchT<NodeKey>::getLeft().findMax();
                *BSearchT<NodeKey>::key = max;
                BSearchT<NodeKey>::getLeft().remove(max);
            }
            else if (!BSearchT<NodeKey>::getRight().isEmpty())
            {
                NodeKey min = BSearchT<NodeKey>::getRight().findMin();
                *BSearchT<NodeKey>::key = min;
                BSearchT<NodeKey>::getRight().remove(min);
            }
            else
                detachKey();
        
    }
    else if (diff<0)
        BSearchT<NodeKey>::getLeft().remove(d);
    else
        BSearchT<NodeKey>::getRight().remove(d);
}


#endif /* MyADTs_hpp */
