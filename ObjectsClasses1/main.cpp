//
//  main.cpp
//  ObjectsClasses1
//
//  Created by Craig Reynolds on 22/04/2024.
//

#include <iostream>
#include <time.h>
#include "MyADTs.hpp"
#include "deitelclasses.hpp"
#include "templateADTS.hpp"

class SimpleClass {
    
friend std::ostream &operator<<(std::ostream& ,const SimpleClass &);

public:
    
    SimpleClass(std::string s="heelo", int i = 0, float f =0.0);
    ~SimpleClass() { };
    
private:
    int theInt;
    float theFloat;
    std::string theString;
};

SimpleClass::SimpleClass(std::string s , int i  , float f )
{
    theInt=i; theFloat = f; theString=s;
}

std::ostream &operator<<(std::ostream& output,const SimpleClass &simple)
{
    output<<"\nInteger: "<<simple.theInt;
    output<<"\nFloat  : "<<simple.theFloat;
    output<<"\nString : "<<simple.theString;
    
    return output;
    
}



int main(int argc, const char * argv[]) {
    
    
 //   int i=0, removed =-1;;
    //Node<int> node(9);

    binaryTree *myTree = new binaryTree;
    int i;
    //srand(time(NULL));


    for (int z=1; z<10;z++)
    {
        i = (rand() % 9) +1;
        std::cout<<" "<<i;
        myTree->insertData(i++);
    }
    std::cout<< "\n Tree:";
    myTree->print(binaryTree::PreOrder);
    
    int toRemove =1;
    

    while (toRemove)
    {
        std::cout<<"\n To Delete:";
        std::cin>>toRemove;
        myTree->deleteData(toRemove);
        myTree->print(binaryTree::PreOrder);
    }
   // std::cout<<myList;
    std::cout <<"\n";
    
    delete myTree;

    return 0;
}
