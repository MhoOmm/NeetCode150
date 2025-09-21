class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        int i = 0;
        int j = n-1;
        vector<int>ans(2,0);
        while(i<=j)
        {
            if((nums[i]+nums[j])>target)
            {
                j--;
            }else if((nums[i]+nums[j])<target)
            {
                i++;
            }else{
                ans[0] = i+1;
                ans[1] = j+1;
                break;
            }

        }

        return ans;
        
    }
};
