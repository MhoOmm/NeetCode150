class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int group) {
        int n = hand.size();
        sort(hand.begin(),hand.end());

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            int start = hand[i];
            if(mp[start]==0)continue;

            for(int j=0;j<group;j++){
                int curr = start+j;
                if(mp[curr]==0)
                {
                    return false;
                }
                mp[curr]--;
            }
        }
        return true;

    }
};
