// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int pivot(int arr[],int low,int  high){
        
        //No elements in the array
        if(high<low) return -1;
        //1 element in the array
        if(high==low) return low;
        
        int mid = (low + high) / 2; /*low + (high - low)/2;*/
        if (mid < high && arr[mid] > arr[mid + 1])
            return mid;

        if (mid > low && arr[mid] < arr[mid - 1])
            return (mid - 1);

        if (arr[low] >= arr[mid])
            return pivot(arr, low, mid - 1);

        return pivot(arr, mid + 1, high);
    }
    int binary(int arr[], int target, int low , int high){
        
        if (high < low)
        return -1;

        int mid = (low + high) / 2; /*low + (high - low)/2;*/
        if (target == arr[mid])
            return mid;

        if (target > arr[mid])
            return binary(arr, target, (mid + 1), high);

        // else
        return binary(arr, target, low, (mid - 1));
    }
    
    int search(int arr[], int l, int h, int target){
    //complete the function here
        int n=h+1;
            int ind = pivot(arr, 0, n - 1);
            if (ind == -1)
                return binary(arr,target, 0, n - 1);
            if (arr[ind] == target)
                return ind;
    
            if (arr[0] <= target)
                return binary(arr,target, 0, ind - 1);
    
            return binary(arr, target, ind + 1, n - 1);
        }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends