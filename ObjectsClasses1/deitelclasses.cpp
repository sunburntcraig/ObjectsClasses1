//
//  deitelclasses.cpp
//  ObjectsClasses1
//
//  Created by Craig Reynolds on 23/04/2024.
//

#include "deitelclasses.hpp"
#include <iostream>



SavingsAccount::SavingsAccount()
{
    savingsBalance = 0;
}

SavingsAccount::SavingsAccount(std::string name,float balance)
{
    SavingsAccount();
    customerName = name;
}

float SavingsAccount::calculateMonthlyInterest()
{
   // return ((annualInterestRate/100) * savingsBalance)/12;
    
    return 0;
}

void SavingsAccount::AddMonthlyInterest()
{
    deposit(calculateMonthlyInterest());
}

void SavingsAccount::deposit(float amount)
{
    savingsBalance += amount;
}

void SavingsAccount::withdrawal(float amount)
{
    savingsBalance -= amount;

}

void SavingsAccount::setSavingsBalace(float balance)
{
    savingsBalance = balance;
}

float SavingsAccount::getSavingsBalance() const
{
    return savingsBalance;
}

void SavingsAccount::setAnnualInterestRate(float newRate)
{
    //annualInterestRate = newRate;
}

int SavingsAccount::getCount()
{
    return 1; // count;
}

// --- Overloaded output operator
std::ostream &operator<<( std::ostream& output,const SavingsAccount &account)
{
    output<<"\nName: "<<account.customerName<<"\n Current Balance: $"<<account.savingsBalance;
    
    return output;
}

std::istream &operator>>( std::istream& input, SavingsAccount &account)
{
    std::string family, first;
    
    std::cout<<"\nFamily Name: ";
    input>>family;
    std::cout<<"\nFirst Name: ";
    input>>first;
    
    family = family +", "+ first;
    account.customerName = family;
    
    std::cout<<"\nOpening Balance: ";
    input>>account.savingsBalance;
    
    return input;
    
}


