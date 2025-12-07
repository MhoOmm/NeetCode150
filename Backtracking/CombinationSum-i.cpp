class Solution {
public:
    int n = 0;
    void solve(int i,int sum,int target,vector<int>& candi,vector<int>&curr,vector<vector<int>>&result){
        if(sum>=target  || i>=n){
            if(sum==target){
                result.push_back(curr);
            }
            return ;
        }

        curr.push_back(candi[i]);
        sum+=candi[i];
        // take
        solve(i,sum,target,candi,curr,result);
        sum-=candi[i];
        curr.pop_back();

        // skip
        solve(i+1,sum,target,candi,curr,result);

    }
    vector<vector<int>> combinationSum(vector<int>& candi, int target) {
        n = candi.size();
        vector<int>curr;
        vector<vector<int>>result;
        solve(0,0,target,candi,curr,result);
        return result;
    }
};