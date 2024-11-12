/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int steps =0;


int nfib(int n)
{
    if(n<=1)
    return n;
    
    int a = 0 , b = 1 , fib=1;
    for(int i=2;i<=n;i++)
    {
        fib = a+b;
        a=b;
        b=fib;
    }
    return fib;
}

int rfib(int n)
{
    if(n<=1)
    return n;
    steps ++;
    return rfib(n-1) + rfib(n-2);
}

int main()
{
   int n;
   cin>>n;
   cout<<"Recursive Fibo"<<endl;
   for(int i=0;i<=n;i++)
   {
       int temp = rfib(i);
       cout<<temp<<" ";
   }
   cout<<endl;
   cout<<"Iterative Fibo"<<endl;
   for(int i=0;i<=n;i++)
   {
       int temp = nfib(i);
       cout<<temp<<" ";
   }
   
 
}