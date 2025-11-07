class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        int n = stones.size();
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size()>1)
        {
           int a= pq.top();
           pq.pop();
           int b = pq.top();
           pq.pop();

           pq.push(a-b);
        }

        int ans = pq.top();
        pq.pop();

        return ans; 
    }
};
