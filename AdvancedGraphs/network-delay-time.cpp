class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &time:times)
        {
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            adj[u].push_back({v,wt});
        }

        // finding the min time to reach from the source to all nodes -> single source multiple dest -> djikstra
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty())
        {
            auto [time,node] = pq.top();
            pq.pop();
            if (time > dist[node]) continue;
            for(auto &neig:adj[node])
            {
                int neigtime = neig.second;
                int neignd = neig.first;
                
                if(neigtime + time < dist[neignd])
                {
                    dist[neignd] = neigtime + time;
                    pq.push({neigtime + time,neignd});
                }
            }
        }
        // getting the maximum time taken by any node-> that node will be the shortest time
        int netDelayTime = INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
            {
                return -1;
            }
            netDelayTime = max(netDelayTime,dist[i]);
        }
        return netDelayTime;
    }
};