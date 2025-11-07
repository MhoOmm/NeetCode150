class Solution {
public:
    long long caneat(int mid,vector<int>& piles, int h ){

        long long countH = 0;
        for(auto &num:piles)
        {
            countH += (num+mid-1)/mid;//ceiling division
        }

        return countH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        long long n = piles.size();
        long long lar = *max_element(piles.begin(),piles.end());

        long long start = 1;
        long long end = lar; 
        long long ans = 1;

        while(start<=end)
        {
            long long mid = start + (end-start)/2 ;
            if(caneat(mid,piles,h)<=h)
            {
                ans = mid; 
                end = mid -1;
            }else{
                start = mid +1;
            }
        }

        return ans;
        
    }
};
