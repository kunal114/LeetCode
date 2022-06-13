class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0];
        int profit = 0;
        for(int i =1; i <n;i++){
            if(prices[i]>mn){
                profit = max(profit,prices[i]-mn);
            }
            else{
                mn = min(mn,prices[i]);
            }
        }
        return profit;
    }
};