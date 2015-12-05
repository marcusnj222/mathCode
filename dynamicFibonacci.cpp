//
//  dynamicFibonacci.cpp
//
//  Created by Marcus Gubanyi on 12/3/15.
//  For: Math 750 Project at the University of Kansas
//  By: Marcus Gubanyi and Nick Oderio
//
//  Introduces dynamic programming by using the intuitive example: the Fibonacci Sequence.
//  Compares three algorithms and their computation times
//     - naive algorithm: a non-dynamic approach using the recursive definition of the sequence.
//     - memoization algorithm: a dynamic approach less commonly used, TOP DOWN.
//     - tabulation algorithm: a typical dynamic approach for most problems, BOTTOM UP.

#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;


#pragma mark naive

/**
 * The recursive definition of the Fibonacci sequence
 * is directly converted into code in this function.
 * F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)
 */
long long int naiveFibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return naiveFibonacci(n-1) + naiveFibonacci(n-2);
    }
}

// Execute and output the naive algorithm.
void naiveScript(int n)
{
    clock_t timeClock;

    if (n < 50)
    {
        timeClock = clock();
        
        long long int fib = naiveFibonacci(n);
        
        timeClock = clock() - timeClock;
        
        cout << "\nNaive Algorithm\n" << "Input: " << n
             << "  |  Result: " << fib << "  |  Computation Time: ";
        
        printf ("%f seconds\n",((float)timeClock)/CLOCKS_PER_SEC);
    }
    else
    {
        cout << "\nNaive computation skipped to save time.\n";
    }
    
}


#pragma mark memoization

const int maxN = 80;

// Stores values for the Fibonacci sequence used in memoization.
// Needs to be global to stay in scope throughout recursive calls.
long long int storedFibNums[maxN+1];


void initializeStoredFibNums()
{
    for (int i = 0; i < maxN+1; i++)
    {
        storedFibNums[i] = 0;
    }
    storedFibNums[1] = 1;
}

/**
 * Memoization algorithm where we save any computation we do, preventing
 * the same computation to be done again.
 */
long long int memoizationFibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else if (storedFibNums[n] == 0)
    {
        storedFibNums[n] = memoizationFibonacci(n-1) + memoizationFibonacci(n-2);
        return storedFibNums[n];
    }
    else
    {
        return storedFibNums[n];
    }
        
}

void memoizationScript(int n)
{
    clock_t timeClock;

    timeClock = clock();
    
    initializeStoredFibNums();
    
    // Dynamically computes the nth Fibonacci number TOP DOWN with memoization.
    long long int fibMem = memoizationFibonacci(n);
    
    timeClock = clock() - timeClock;
    
    cout << "\nMemoization Algorithm\n" << "Input: " << n
         << "  |  Result: " << fibMem << "  |  Computation Time: ";
    
    printf ("%f seconds\n",((float)timeClock)/CLOCKS_PER_SEC);
}

#pragma mark tabulation

/**
 *
 */
long long int tabulationFibonacci(int n)
{
    long long int fibNums[n+1];
    fibNums[0] = 0;
    fibNums[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        fibNums[i] = fibNums[i-1] + fibNums[i-2];
    }
    
    return fibNums[n];
}

void tabulationScript(int n)
{
    clock_t timeClock;

    timeClock = clock();
    
    long long int fibTab = tabulationFibonacci(n);
    
    timeClock = clock() - timeClock;
    
    cout << "\nTabulation Algorithm\n" << "Input: " << n
         << "  |  Result: " << fibTab << "  |  Computation Time: ";
    
    printf ("%f seconds\n\n\n",((float)timeClock)/CLOCKS_PER_SEC);
}

#pragma mark main script

int main()
{
    // These values cannot be greater than maxN declared for memoization.
    int nArray[8] = {10,20,30,40,50,60,70,80};
    
    for (int i = 0; i < 8; i++)
    {
        int n = nArray[i];
        
        naiveScript(n);
        memoizationScript(n);
        tabulationScript(n);
    }
    
    return 0;
}
