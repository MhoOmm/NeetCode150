class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {

        vector<int>inDeg(num);
        vector<vector<int>>adj(num);
        for(auto &edge:pre)
        {
            int second = edge[0];
            int first = edge[1];

            adj[first].push_back(second);
            inDeg[second]++;
        }  

        int count =0;
        queue<int>q;
        for(int i=0;i<num;i++)
        {
            if(inDeg[i]==0)
            {
                q.push(i);
            }
        }   

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(auto &neig:adj[node])
            {
                inDeg[neig]--;
                if(inDeg[neig]==0)
                {
                    q.push(neig);
                }
            }
        } 

        return count==num?true:false ;
    }
};