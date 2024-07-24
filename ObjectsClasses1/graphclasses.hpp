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
#include <list>



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
    
    friend bool operator==(edge<KeyType>& e1, edge<KeyType>& e2)
    {
        return (e1.v1 == e2.v1) && (e1.v2 == e2.v2);
    }
    
    friend void getVertices(edge<KeyType>& e, vertex<KeyType>& vert1, vertex<KeyType>& vert2)
    {
        vert1 = e.v1;
        vert2 = e.v2;
    }
};
                   
template< class KeyType >
class graph
{

protected:
    static const int vertexInit = 10;
    static const int edgeincrement = 5;
    
    long vertexCount, edgeCount;
    
    int vertexOffset(KeyType);
    std::vector<vertex<KeyType>> vertices;
    
public:
    graph(): vertexCount(0), edgeCount(0) {};
    bool vertexExists(KeyType);
    bool vertexExists(vertex<KeyType>&);
    void addVertex(KeyType);
    void addVertex(vertex<KeyType>& );
    void removeVertex(KeyType);
    void removeVertex(vertex<KeyType>&);
    void printVertices();
    long numEdges() {return edgeCount;};
    long numVertices() {return vertexCount;};

    virtual bool edgeExists(KeyType , KeyType ) =0 ;
    virtual bool edgeExists(edge<KeyType>&) =0 ;
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
   
    void expandMatrix();
    long edgeSize;
    int edges[graphAdjacency::vertexInit][graphAdjacency::vertexInit];

public:
    graphAdjacency();
    virtual void addEdge(KeyType, KeyType);
    virtual void addEdge(edge<KeyType>&);
    virtual void deleteEdge(KeyType , KeyType);
    virtual void deleteEdge(edge<KeyType>&);
    virtual void printEdges();
};

// ----- graph using linked list for edges

template< class KeyType >
class graphList : public graph<KeyType>
{
    // class impletemente using adjaceny list for edges
    //std::list<vertex<KeyType>>* edges[graphList::vertexInit];
    std::vector< std::list< vertex<KeyType> > > edges;

    
public:
    graphList();
    virtual void addEdge(KeyType, KeyType);
    virtual void addEdge(edge<KeyType>&);
    virtual void deleteEdge(KeyType , KeyType);
    virtual void deleteEdge(edge<KeyType>&);
    virtual bool edgeExists(KeyType , KeyType ) ;
    virtual bool edgeExists(edge<KeyType>&)  ;
    virtual void printEdges();
};
 
 
 //-------vertex methods
 template< class KeyType >
 bool operator==(vertex<KeyType>& k1, vertex<KeyType>& k2)
 {
     return k1.Key() == k2.Key();
 }

 //-------edge methods

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


/*
 //--- friend methods.
 // NB these have been moved to the edge class to counter compiler isssues
 // caused by templates
 template< class KeyType >
  bool operator==(edge<KeyType>& e1, edge<KeyType>& e2)
 {
      return (e1.v1 == e2.v1) && (e1.v2 == e2.v2);
 };

template< class KeyType >
void getVertices(edge<KeyType>& e, vertex<KeyType>& vert1, vertex<KeyType>& vert2)
{
    vert1 = e.v1;
    vert2 = e.v2;
}
*/

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
     if ( vertexExists(k))
         return;
     
     vertex<KeyType> newV(k);
     addVertex(newV);
     
 }

 template< class KeyType >
 void graph<KeyType>::addVertex(vertex<KeyType>& newV)
 {
     vertices.push_back(newV);
     vertexCount++;
 }

 template< class KeyType >
 void graph<KeyType>::removeVertex(KeyType k)
 {
     typename std::vector<vertex<KeyType>>::iterator it = vertices.begin();
     
     for (; it != vertices.end(); ++it)
         if (it->Key() == k)
         {
             vertices.erase(it);
             vertexCount--;
             break;
         }
     
 }

 template< class KeyType >
 void graph<KeyType>::removeVertex(vertex<KeyType>& delV)
 {
     
     removeVertex(delV.Key());
 }

template< class KeyType >
int graph<KeyType>::vertexOffset(KeyType k)
{
    int offset = -1;
    int i =0;
    
    typename std::vector<vertex<KeyType>>::iterator it = vertices.begin();
    for (; it != vertices.end(); ++it, i++)
        if (it->Key() == k)
        {
            offset = i;
            break;
        }
            
    return offset;
}


 template< class KeyType >
 void graph<KeyType>::printVertices()
 {
     typename std::vector<vertex<KeyType>>::iterator it = vertices.begin();
     vertex<KeyType> lastVertex = vertices.back();
     
     
     std::cout<<"\n vertices { ";
     for (; it != vertices.end(); ++it)
         if ( it->Key() == lastVertex.Key() )
             std::cout<<it->Key()<<" ";
         else
             std::cout<<it->Key()<<", ";

     std::cout<<" }";
 }


 // -----adjacency graph methods

template< class KeyType >
graphAdjacency<KeyType>::graphAdjacency() : graph<KeyType>()
{
   // auto arr2d = new int [graphAdjacency::vertexInit][graphAdjacency::vertexInit];
   // edges = arr2d;
    graphAdjacency::edgeCount =0;
    edgeSize = graphAdjacency::vertexInit;
    
    for (int row =0; row < graphAdjacency::vertexInit; row++)
        for (int col = 0; col <graphAdjacency::vertexInit; col++)
            edges[row][col] =0;
    
};


 template< class KeyType >
 void graphAdjacency<KeyType>::addEdge(KeyType vertex1, KeyType vertex2)
 {
     if ( graphAdjacency::vertexExists(vertex1) && graphAdjacency::vertexExists(vertex2))
     {
         edges[graphAdjacency::vertexOffset(vertex1)][graphAdjacency::vertexOffset(vertex2)] = 1;
         edges[graphAdjacency::vertexOffset(vertex2)][graphAdjacency::vertexOffset(vertex1)] = 1;
         graphAdjacency::edgeCount++;
     }
     
 }

 template< class KeyType >
 void graphAdjacency<KeyType>::addEdge(edge<KeyType>& e)
 {
    
 }

 template< class KeyType >
 void graphAdjacency<KeyType>::deleteEdge(KeyType vertex1, KeyType vertex2)
 {
     if ( graphAdjacency::vertexExists(vertex1) && graphAdjacency::vertexExists(vertex2))
     {
         edges[graphAdjacency::vertexOffset(vertex1)][graphAdjacency::vertexOffset(vertex2)] = 0;
         edges[graphAdjacency::vertexOffset(vertex2)][graphAdjacency::vertexOffset(vertex1)] = 0;
         graphAdjacency::edgeCount--;
     }
  
 }

 template< class KeyType >
 void graphAdjacency<KeyType>::deleteEdge(edge<KeyType>& e)
 {
     
 }

 template< class KeyType >
 void graphAdjacency<KeyType>::printEdges()
 {
     for (int row =0; row < graphAdjacency::vertexInit; row++)
         for (int col = 0; col <graphAdjacency::vertexInit; col++)
            if ( edges[row][col] )
                std::cout<< "\n Edge: "<<row<<" - "<<col;
     
 }


// ------- edge list graph methods
template< class KeyType >
graphList<KeyType>::graphList(): graph<KeyType>()
{
    graphList::edgeCount =0;
    
    for (int row =0; row < graphList::vertexInit; row++)
    {
        edges.push_back(*(new std::list<vertex<KeyType>>));
    }
    
};

template< class KeyType >
void graphList<KeyType>::addEdge(KeyType vertex1, KeyType vertex2)
{
    
    if ( edgeExists(vertex1, vertex2) )
        return;
    
    // edge v1 - v2
    edges[graphList<KeyType>::vertexOffset(vertex1)].push_back(vertex2);

    // edge v2 - v1
    edges[graphList<KeyType>::vertexOffset(vertex2)].push_back(vertex1);
    
    graphList<KeyType>::edgeCount++;
    
}

template< class KeyType >
void graphList<KeyType>::addEdge(edge<KeyType>&)
{
   
}

template< class KeyType >
void graphList<KeyType>::deleteEdge(KeyType vertex1, KeyType vertex2)
{
    
    if ( !edgeExists(vertex1, vertex2) )
        return;
    
    // delete edge v1 - v2
    auto it = edges[graphList<KeyType>::vertexOffset(vertex1)].begin(); // initialiazation done here for legibility
    
    for (;it != edges[graphList<KeyType>::vertexOffset(vertex1)].end();++it)

        if ( it->Key() == vertex2)
        {
            edges[graphList<KeyType>::vertexOffset(vertex1)].erase(it);
            break;
        }
  
    it = edges[graphList<KeyType>::vertexOffset(vertex2)].begin(); // initialiazation done here for legibility

    for (;it != edges[graphList<KeyType>::vertexOffset(vertex2)].end();++it)
        if ( it->Key() == vertex1)
        {
            edges[graphList<KeyType>::vertexOffset(vertex2)].erase(it);
            break;
        }
    
    graphList<KeyType>::edgeCount--;
    
}

template< class KeyType >
void graphList<KeyType>::deleteEdge(edge<KeyType>& e)
{
    vertex<KeyType> vert1, vert2;
    getVertices(e,vert1,vert2);
    deleteEdge(vert1.Key(), vert2.Key());
}

template< class KeyType >
bool graphList<KeyType>::edgeExists(KeyType vertex1, KeyType vertex2)
{
    
    // Only need to check if one direction exists
    int vertOffset = graphList<KeyType>::vertexOffset(vertex1);

    if (edges[vertOffset].size() == 0)
        return false;

    for (auto v = edges[vertOffset].begin(); v != edges[vertOffset].end(); ++v)
         if (v->Key() == vertex2)
                return true;
    
    return false;
}

template< class KeyType >
bool graphList<KeyType>::edgeExists(edge<KeyType>& e)
{
    vertex<KeyType> vert1, vert2;
    getVertices(e,vert1,vert2);
    return edgeExists(vert1.Key(), vert2.Key());
}

template< class KeyType >
void graphList<KeyType>::printEdges()
{
    std::cout<<"\nEdges from: ";
    
    int i = 0;
    
    for (auto v1 = edges.begin(); v1 < edges.end(); ++v1, ++i)
    {       if (i < graphList<KeyType>::vertexCount)
             std::cout<<"\n "<<graphList<KeyType>::vertices[i].Key()<<": ";
        
            for (auto v2 = v1->begin(); v2 != v1->end(); ++v2)
                std::cout<<v2->Key() <<" ";
    }
  
}



#endif /* graphclasses_hpp */
