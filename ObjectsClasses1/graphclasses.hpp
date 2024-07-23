//
//  graphclasses.hpp
//  ObjectsClasses1
//
//  Created by Craig Reynolds on 22/07/2024.
//

#ifndef graphclasses_hpp
#define graphclasses_hpp

#include <stdio.h>
#include <vector>
#include <iostream>



template< class KeyType >
class vertex
{
    KeyType key;   //assume all keys are > 0
public:
    vertex() :key(0) {};
    vertex(KeyType k): key(k) {};
    KeyType Key() {return key;};
    void setKey(KeyType k) {key = k;};
    friend bool operator==(vertex&, vertex&);
};

template< class KeyType >
class edge
{
    vertex<KeyType> v1, v2;
    int weight;
    
public:
    edge(): v1(0), v2 (0), weight(0) {};
    edge(KeyType V1, KeyType V2, int W = 0): v1(V1), v2(V2), weight (W) {};
    void setEdge(KeyType V1, KeyType V2, int W = 0) { v1= V1;  v2=V2; weight=W;};
    vertex<KeyType>& adjacent (KeyType);
    vertex<KeyType>& adjacent (vertex<KeyType>&);
    void setWeight(int );
    int getweight() const;
    friend bool operator==(edge&, edge&);
};
                   
template< class KeyType >
class graph
{
    static const int vertexInit = 10;
    static const int edgeInit = 10;
    static const int edgeincrement = 5;
    
    std::vector<vertex<KeyType>> vertices;
    long vertexCount, edgeCount;
    
public:
    graph(): vertexCount(0), edgeCount(0) {};
    bool vertexExists(KeyType);
    bool vertexExists(vertex<KeyType>&);
    void addVertex(KeyType);
    void addVertex(vertex<KeyType>& );
    void removeVertex(KeyType );
    void removeVertex(vertex<KeyType>&);
    void printVertices();

    virtual void addEdge(KeyType , KeyType ) =0 ;
    virtual void addEdge(edge<KeyType>&) = 0 ;
    virtual void deleteEdge(KeyType , KeyType) =0 ;
    virtual void deleteEdge(edge<KeyType>&) = 0;
    virtual void printEdges() = 0;

};

template< class KeyType >
class graphAdjacency : public graph<KeyType>
{
    // class impletemente using adjaceny matrix for edges
    // start with 10 and dynamically grow as needed
    int* edges<KeyType>;

public:
    graphAdjacency() : graph<KeyType>() {};
    virtual void addEdge(KeyType, KeyType);
    virtual void addEdge(edge<KeyType>&);
    virtual void deleteEdge(KeyType , KeyType);
    virtual void deleteEdge(edge<KeyType>&);
    virtual void printEdges();
};

template< class KeyType >
class graphList : public graph<KeyType>
{
    // class impletemente using adjaceny list for edges
    
    
public:
    graphList();
    virtual void addEdge(KeyType, KeyType);
    virtual void addEdge(edge<KeyType>&);
    virtual void deleteEdge(KeyType , KeyType);
    virtual void deleteEdge(edge<KeyType>&);
    virtual void printEdges();
};
 
 
 //-------vertex methods
 template< class KeyType >
 bool operator==(vertex<KeyType>& k1, vertex<KeyType>& k2)
 {
     return k1.Key() == k2.Key();
 }

 //-------edge methogs

 template< class KeyType >
 vertex<KeyType>& edge<KeyType>::adjacent (KeyType V)
 {
     if (V == v1.Key() )
         return v2;
     
     if (V == v2.Key() )
         return v1;
     
     // better to throw an exception here otherwise we have memory leaks.
     vertex<KeyType>* retV = new vertex<KeyType>(0);
     return *retV;
 }

 template< class KeyType >
 vertex<KeyType>& edge<KeyType>::adjacent (vertex<KeyType>& V)
 {
    return adjacent( V.Key() );
 }

 template< class KeyType >
 void edge<KeyType>::setWeight(int W )
 {
     if (W > 0)
         weight = W;
 }

 template< class KeyType >
 int edge<KeyType>::getweight() const
 {
     return weight;
 }

 template< class KeyType >
  bool operator==(edge<KeyType>& e1, edge<KeyType>& e2)
 {
      return (e1.v1 == e2.v1) && (e1.v2 == e2.v2);
 };


 //----------graph abstract class methods

 template< class KeyType >
 bool graph<KeyType>::vertexExists(KeyType k)
 {
     typename std::vector<vertex<KeyType>>::iterator it = vertices.begin();
     
     for (; it != vertices.end(); ++it)
         if (it->Key() == k)
             return true;
     
     return false;
 }

 template< class KeyType >
 bool graph<KeyType>::vertexExists(vertex<KeyType>& v)
 {
     return vertexExists(v.Key());
 }

 template< class KeyType >
 void graph<KeyType>::addVertex(KeyType k)
 {
     vertex<KeyType> newV(k);
     addVertex(newV);
     
 }

 template< class KeyType >
 void graph<KeyType>::addVertex(vertex<KeyType>& newV)
 {
     vertices.push_back(newV);
     vertexCount = vertices.size();
 }

 template< class KeyType >
 void graph<KeyType>::removeVertex(KeyType k)
 {
     typename std::vector<vertex<KeyType>>::iterator it = vertices.begin();
     
     for (; it != vertices.end(); ++it)
         if (it->Key() == k)
         {
             vertices.erase(it);
             break;
         }
     
 }

 template< class KeyType >
 void graph<KeyType>::removeVertex(vertex<KeyType>& delV)
 {
     
     removeVertex(delV.Key());
     
 }

 template< class KeyType >
 void graph<KeyType>::printVertices()
 {
     typename std::vector<vertex<KeyType>>::iterator it = vertices.begin();
     
     std::cout<<"\n vertices { ";
     for (; it != vertices.end(); ++it)
         std::cout<<it->Key()<<", ";
     
     std::cout<<" }";
 }


 // -----adjacency graph methods



 template< class KeyType >
 void graphAdjacency<KeyType>::addEdge(KeyType vertex1, KeyType vertex2)
 {
     
 }

 template< class KeyType >
 void graphAdjacency<KeyType>::addEdge(edge<KeyType>& e)
 {
     
 }

 template< class KeyType >
 void graphAdjacency<KeyType>::deleteEdge(KeyType vertex1, KeyType vertex2)
 {
     
 }

 template< class KeyType >
 void graphAdjacency<KeyType>::deleteEdge(edge<KeyType>& e)
 {
     
 }

 template< class KeyType >
 void graphAdjacency<KeyType>::printEdges()
 {
     
 }



#endif /* graphclasses_hpp */
