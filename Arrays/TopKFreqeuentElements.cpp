class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(auto &num:nums)
       {
        mp[num]++;
       }
       vector<pair<int,int>>vect;
       for(auto &it:mp)
       {
        vect.push_back({it.first,it.second});
       }

       sort(begin(vect),end(vect),[](auto &a,auto &b){
            return a.second>b.second;
       });

       vector<int>ans;
       for(int i=0;i<k;i++)
       {
        ans.push_back(vect[i].first);
       }

       return ans;
    }
};
