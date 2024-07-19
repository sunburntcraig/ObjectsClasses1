//
//  main.cpp
//  ObjectsClasses1
//
//  Created by Craig Reynolds on 22/04/2024.
//

#include <iostream>
#include <time.h>
#include <stack>
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

bool isDigit(const char character)
{
    bool found = false;
    char theDigits[] = {'0','1','2','3','4','5','6','7','8','9'};

    for (int i = 0; i<10; i++)
        if (theDigits[i] == character)
            found =true;
    
    return found;
}

char theOperators[] = {'^','/','%','*','+','-'};

bool isOperator(const char character)
{
    bool found = false;
    // char theOperators[] = {'^','/','%','*','+','-'};
    
    for (int i = 0; i<6; i++)
        if (theOperators[i] == character)
            found =true;
    
    return found ;
}

bool higherprecedence(const char operator1,const char operator2)
{
   // char theOperators[] = {'-','+','*','%','/','^'};
    
    int op1, op2;
    
    for (int i = 0; i<6; i++)
    {
        if (theOperators[i] == operator1) op1 = i;
        if (theOperators[i] == operator2) op2 = i;
    }
    
    return (op1 >= op2);
}

void infixToPostFix(std::string infixExpression)
{
    int i=0;
    std::stack<char> theStack, tempStack;
    std::string postfix ="";
  
    theStack.push('(');
    infixExpression = infixExpression + ")";
    
    while (!theStack.empty())
    {
        if (isDigit(infixExpression[i]))
            postfix = postfix+infixExpression[i];
        
        if (infixExpression[i] == '(')
            theStack.push('(');
        
        if (isOperator(infixExpression[i]))
            {
                   while (isOperator(theStack.top()) && higherprecedence(theStack.top(),infixExpression[i]))
                   {
                       postfix=postfix+theStack.top();
                       theStack.pop();
                   }
                theStack.push(infixExpression[i]);
             }
        
        if (infixExpression[i] == ')')
        {
            while (theStack.top()!='(')
            {
                postfix=postfix + theStack.top();
                theStack.pop();
            }
        
            theStack.pop();
        }
       std::cout<<"\n PostFix: "<<postfix;
        i++;
     }
    
}



int main(int argc, const char * argv[]) {
    
    //binaryTree theTree;
    //int data;
    
    std::cout<<"\n Generate:";
 /*   for (int i = 0; i<30;i++)
    {
        std::cout<<" "<<(data = random()% 20);
        theTree.insertData(data);
    }
    
    theTree.print(binaryTree::PreOrder);
    
    theTree.breadthFirstTraversal();
   */
    int num = 9;
    BSearchT<int>* tree = new BSearchT<int>(num);
    
    for (int i = 0; i<30;i++)
        {
            int data;
            std::cout<<" "<<(data = random()% 30);
            tree->attachKey(data);
            
            std::cout<<"\nMin:"<<tree->findMin()<<"  Max:"<<tree->findMax()<<" ";
            
        }
    
    std::cout<<"\n\n Pre:";
    tree->depthFirstTraverse(PreOrder);
    std::cout<<"\n In:";
    tree->depthFirstTraverse(InOrder);
    std::cout<<"\n Post";
    tree->depthFirstTraverse(PostOrder);

    
    
    std::cout <<"\n";
    

    return 0;
}
