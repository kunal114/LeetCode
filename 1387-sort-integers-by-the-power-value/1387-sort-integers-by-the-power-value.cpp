class Solution {
public:
    // static bool compare(const pair<int,int> &a,const pair<int,int> &b)
    //     {
    //         return (a.second < b.second);
    //     }
    int solve(int x){
        
        if(x==1)
            return 0;
        int ans;
        if(x%2==0)
            ans=1+solve(x/2);
          else
          ans=1+solve(x*3+1);
          return ans;
    }
    int getKth(int lo, int hi, int k) {
        
        vector<pair<int,int>> ans;
        for(int i=lo;i<=hi;i++){
            int power = solve(i);
            cout<<i<<" ";
            cout<<power<<" "<<endl;
            ans.push_back(make_pair(power,i));
        }
        cout<<endl;
        sort(ans.begin(), ans.end());
        return ans[k-1].second;
    }
};