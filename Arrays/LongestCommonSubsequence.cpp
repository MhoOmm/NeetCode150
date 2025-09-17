class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        {
            return 0;
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int maxcount=1;

        for(int it:st)
        {
            int streak = 1;
            int currnum = it;   
            if(st.find(it-1)!=st.end())continue;
            while(st.find(currnum+1)!=st.end())
            {
                streak+=1 ;
                currnum+=1;
            }
            maxcount = max(maxcount,streak);
        }

        return maxcount;
    }
};