// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int array[], int N, int difference){
    //code
    sort(array,array+N);
    int i = 0;  
    int j = 1;
    while(i<N && j<N)
    {
        if (i != j && array[j]-array[i] == difference)
        {
            return 1;
        }
        else if (array[j]-array[i] < difference) 
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return 0;
}