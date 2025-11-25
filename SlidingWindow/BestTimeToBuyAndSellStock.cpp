// Best Time to Buy and Sell Stock -i
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int result = 0 ;
        int mini = prices[0];

        for(int i =1;i<n;i++)
        {
            int cost = prices[i]-mini;
            result = max(result,cost);
            mini = min(mini,prices[i]);

        }
        return result;
        
    }
};

