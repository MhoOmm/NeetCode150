class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge:flights)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src] = 0;
        int level= 0;
        while(!q.empty() && level<=k )
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front().first;
                int wt = q.front().second ;
                q.pop();

                for(auto &neig:adj[node])
                {
                    int v = neig.first;
                    int tow = neig.second;

                    if(wt+tow<dist[v])
                    {
                        dist[v]=wt+tow;
                        q.push({v,wt+tow});
                    }
                }
            }
            level++;
        }

        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};