class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xornum = 0;
        for(int i =0;i<n;i++)
        {
            xornum = xornum^nums[i];
        }
        return xornum;
    }
};
