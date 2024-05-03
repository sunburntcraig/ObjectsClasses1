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
    btNode( int = 0, btNode* = NULL, btNode* = NULL);
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
    btNode *nextLeftNode;
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
    bool isEmpty() { return (root == NULL);};
    enum traverse { PreOrder, InOrder, PostOrder};
    void print(const traverse);
    const btNode * find(const int target);
    void levelOrderTraversal();
    
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




#endif /* MyADTs_hpp */
