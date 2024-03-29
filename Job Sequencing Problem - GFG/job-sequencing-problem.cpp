// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool Compare(struct Job a,struct Job b){
        return a.profit>b.profit;
}
class Solution 
{
    public:
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int pro=0,jobs=0;
        vector<int> ans;
        sort(arr,arr+n,Compare);
        bool slot[n]={0};
                
        for(int i=0;i<n;i++){
            //min(n,arr[i].dead-1) is considered as some deadline can be greater than no of slots available
            for(int j=min(n,arr[i].dead-1);j>=0;j--){
                if(slot[j] == false){
                    pro+=arr[i].profit;
                    jobs++;
                    slot[j] = true;
                    break;
                }
            }
        }
        ans.push_back(jobs);
        ans.push_back(pro);
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends