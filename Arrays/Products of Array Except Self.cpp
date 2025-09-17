class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n  = nums.size();
        vector<int>prefixMul(n,1);
        vector<int>suffix(n,1);
        prefixMul[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            prefixMul[i] = prefixMul[i-1]*nums[i];
        }
        suffix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1] * nums[i];
        }

        vector<int>ans(n,1);
        ans[0] = suffix[1];
        ans[n-1] = prefixMul[n-2];
        for(int i=1;i<n-1;i++)
        {
            ans[i] = prefixMul[i-1]*suffix[i+1];
        }

        return ans;
    }
};

// another approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0] = 1;
        
        for(int i = 1; i<nums.size(); i++) {
            result[i] = result[i-1]*nums[i-1];
        }
        
        int right = 1;
        for(int i = n-1; i>=0; i--) {
            result[i] = result[i]*right;
            right *= nums[i];
        }
        
        return result;
    }
};

