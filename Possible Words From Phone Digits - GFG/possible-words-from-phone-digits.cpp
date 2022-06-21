// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

string keypad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void rec(int a[],int n,int i,string s,vector<string> &ans){
        if(i==n){
            ans.push_back(s);
            return;
        }
        
        int curr_digit = a[i];
        if(curr_digit==0 || curr_digit==1){
            rec(a,n,i+1,s,ans);
        }
        
        for(int j=0;j<keypad[curr_digit].size();++j){
            rec(a,n,i+1,s+keypad[curr_digit][j],ans);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        rec(a,N,0,"",ans);
        return ans;
         
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends