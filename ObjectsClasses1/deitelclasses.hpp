//
//  deitelclasses.hpp
//  ObjectsClasses1
//
//  Created by Craig Reynolds on 23/04/2024.
//

#ifndef deitelclasses_hpp
#define deitelclasses_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>


class SavingsAccount{
    
    friend std::ostream &operator<<( std::ostream&,const SavingsAccount &);
    friend std::istream &operator>>( std::istream&, SavingsAccount &);

    
public:
    SavingsAccount();
    SavingsAccount(std::string,float);
    void AddMonthlyInterest();
    void setSavingsBalace(float);
    float getSavingsBalance() const;
    void deposit(float);
    void withdrawal(float);
    static void setAnnualInterestRate(float);
    static int getCount();

private:
    float calculateMonthlyInterest();
   
    float savingsBalance;
    std::string customerName;
    
    static float annualInterestRate;
    static int count;
    
    
};


#endif /* deitelclasses_hpp */
