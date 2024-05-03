//
//  templateADTS.hpp
//  ObjectsClasses1
//
//  Created by Craig Reynolds on 30/04/2024.
//

#ifndef templateADTS_hpp
#define templateADTS_hpp

#include <stdio.h>
#include <iomanip>


// ------------ templatized Linked List

template< class NodeDataType >
class Node {
    
friend std::ostream &operator<<(std::ostream&, const Node<NodeDataType> &);
    
public:
    Node(const NodeDataType & );
    ~Node();
    void setData(const NodeDataType &);
    NodeDataType getData() const;
    Node * getNext();
    void setNext(Node *);
    
private:
    NodeDataType nodeData;
    Node *nextNode;
};

template<class NodeDataType>
class LinkedList
{
    
friend std::ostream &operator<<(std::ostream&, const LinkedList<NodeDataType> &);

public:
    LinkedList();
    ~LinkedList();
    void putEnd(const NodeDataType &);
    bool removeEnd(NodeDataType &);
    void putStart(const NodeDataType &);
    bool removeStart(NodeDataType &);
    bool find(const NodeDataType &);
    bool isEmpty();
    void print();
    
private:
    Node<NodeDataType> *first, *last;
    int count;
};

//--------ADT Templatized Linked List

template< class NodeDataType >
Node<NodeDataType>::Node(const NodeDataType & data)
{
    setData(data);
}

template< class NodeDataType >
Node<NodeDataType>::~Node()
{
    //delete nodeInfo;
}

template< class NodeDataType >
void Node<NodeDataType>::setData(const NodeDataType &data)
{
    nodeData = data;
}

template< class NodeDataType >
NodeDataType Node<NodeDataType>::getData() const
{
    return nodeData;
}

template< class NodeDataType >
Node<NodeDataType> *Node<NodeDataType>::getNext()
{
    return nextNode;
}

template< class NodeDataType >
void Node<NodeDataType>::setNext(Node *ptrNext)
{
    nextNode = ptrNext;
}


template< class NodeDataType >
LinkedList<NodeDataType>::LinkedList() : first(NULL),last(NULL),count(0)
{
    //empty, initialized above
}

template< class NodeDataType >
LinkedList<NodeDataType>::~LinkedList()
{
    Node<NodeDataType> *iter = first;
    
    while (first!=NULL)
    {
        first = iter->getNext();
        delete iter;
        iter = first;
    }
}

template< class NodeDataType >
    void LinkedList<NodeDataType>::putEnd(const NodeDataType &node)
{
        Node<NodeDataType> *newNode = new Node<NodeDataType>(node), *iter = NULL;

        newNode->setNext(NULL);
        
        if (first == NULL)
        {
            first = last = newNode;
        }
        else
        {   iter = first;
            
            while (iter != last)
                iter =iter->getNext();
            
            last->setNext(newNode);
            last = newNode;
        }
        
        count++; 
        
    }


template< class NodeDataType >
bool LinkedList<NodeDataType>::removeEnd(NodeDataType &node)
{
    Node<NodeDataType> *prior;
    
    if (isEmpty())
        return false;
    
    node = last->getData();
    
    if (first == last)
    {
        delete last;
        first = last = NULL;
    }
   else
    {
        prior = first;
        while (prior->getNext() != last)
            prior = prior->getNext();

        delete last;
        prior->setNext(NULL);
        last = prior;
       
    }
    count--;
    return true;
}

template< class NodeDataType >
void LinkedList<NodeDataType>::putStart(const NodeDataType &node)
{
    Node<NodeDataType> *newNode = new Node<NodeDataType>(node);
    
    if (isEmpty())
    {
       first = last = newNode;
       newNode->setNext(NULL);
    }
   else
    {
        newNode->setNext(first);
        first = newNode;
    }
    
    count++;

}

template< class NodeDataType >
bool LinkedList<NodeDataType>::removeStart(NodeDataType &node)
{
    if (isEmpty())
        return false;
    
    Node<NodeDataType> *oldNode = first;
    node = oldNode->getData();
    
    if (first == last)
        first = last = NULL;
    else
        first = first->getNext();

    delete oldNode;
    count--;
    return true;
}

template< class NodeDataType >
    bool LinkedList<NodeDataType>::find(const NodeDataType &node)
{
        
    }

template< class NodeDataType >
    bool LinkedList<NodeDataType>::isEmpty()
{
        return (count == 0);
        
    }

template< class NodeDataType >
void LinkedList<NodeDataType>::print()
{
    Node<NodeDataType>* iter = first;
    
    std::cout<<"\nList";
    
    if (iter == NULL)
        std::cout<<" is Empty!";
    else
    {
        while (iter!=NULL)
        {
            std::cout<< " "<<iter->getData();
            iter = iter->getNext();
        }
    }
    
}


template< class NodeDataType >
std::ostream &operator<<(std::ostream &output, const Node<NodeDataType> &node)
{
    std::cout<<" " << node.nodeInfo;
    return output;
}
 
template< class NodeDataType >
std::ostream &operator<<(std::ostream &output, const LinkedList<NodeDataType> &theList)
{
    Node<NodeDataType>* iter = theList.first;
    
    std::cout<<"\nList";
    
    if (iter == NULL)
        std::cout<<" is Empty!";
    else
    {
        while (iter!=NULL)
        {
            std::cout<< " "<<iter->getData();
            iter = iter->getNext();
        }
    }
}
 



#endif /* templateADTS_hpp */
