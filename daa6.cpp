#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr , int low , int high)
{
    int piv = arr[low];
    int i = low ;
    int j = high;
    
    while(i<j)
    {
        while(arr[i] <= piv && i<=high-1)
        i++;
        
        while(arr[j] > piv && j>=low+1)
        j--;
        
        
        if(i<j)
        swap(arr[i] , arr[j]);
        
    }
    swap(arr[low] , arr[j]);
    return j;
    
}

// Recursive quicksort function using randomized partition
void randomized_quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = randomized_partition(arr, low, high);
        randomized_quicksort(arr, low, pivot - 1);
        randomized_quicksort(arr, pivot + 1, high);
    }
}
void qs(vector<int>&a , int low , int high)
{
    if(low < high)
    {
        int piviot = partition(a , low , high);
        qs(a , low , piviot-1);
        qs(a , piviot+1 , high);
    }
}
int main()
{
    int n ;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    qs(a , 0 , n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
