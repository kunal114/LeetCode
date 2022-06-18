// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> vis(26,0);//check if char is present in the stream or not
		    string ans="";
		    vector<char> v;//stream
		    
		    for(int i=0;i<A.length();i++){
		        //if char not in stream, push it
		        if(!vis[A[i]-'a']){
		            v.push_back(A[i]);
		        }
		        vis[A[i]-'a']++;//counter of char
		        int f = 0;//check for repeating char
		        
		        //loop for traversing the stream for first non repeating char
		        for(int j=0;j<v.size();j++){
		            //checking in stream
		            if(vis[v[j]-'a']==1){
		                ans.push_back(v[j]);
		                f=1;
		                break;
		            }
		        }
		        if(f==0){
		            ans.push_back('#');
		        }
		        
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends