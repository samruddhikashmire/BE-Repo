#include <bits/stdc++.h>
using namespace std;


struct item {
    int value , weight;
};

bool static comp(item a , item b)
{
    double r1 = (double) a.value/(double) a.weight;
    double r2 = (double) b.value/(double) b.weight;
    
    return r1>r2;
}

double knapsack(item arr[] , int n , int w)
{
    sort(arr , arr+n , comp);
    double total = 0.0;
    int currweight =0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight < w)
        {
            total += arr[i].value;
            w = w - arr[i].weight;
            
        }
        else
        {
            double temp = arr[i].value/(double)arr[i].weight;
            total += temp * (double)w;
            break;
        }
        
    }
    
    return total;
}

int main()
{
   int n = 3, weight = 50;
   item arr[n] = { {100,20},{60,10},{120,30} };
   double ans = knapsack( arr, n , weight);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0; 
}