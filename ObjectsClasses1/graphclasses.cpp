//
//  graphclasses.cpp
//  ObjectsClasses1
//
//  Created by Craig Reynolds on 22/07/2024.
//

#include "graphclasses.hpp"
#include <vector>
#include <iostream>


// class and methods are defined in accompanying .hpp file
// otherwise the compiler throws errors.

/*

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
*/
