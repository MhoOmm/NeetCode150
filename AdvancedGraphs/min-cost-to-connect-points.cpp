class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i)
    {
        if(i==parent[i])
        {
            return i;
        }

        return parent[i]  = find(parent[i]);
    }

    void Union(int x,int y)
    {
        int parx = find(x);
        int pary = find(y);
        if(parx == pary )
        {
            return;
        }

        if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }
        else if(rank[pary]>rank[parx])
        {
            parent[parx] = pary;
        }
        else {
            parent[parx] = pary;
            rank[pary]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        rank.resize(n);
        for(int i =0;i<n;i++)
        {
            parent[i] = i;
            rank[i] =0;
        }
        vector<vector<int>>edges;
        for(int i =0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);
                edges.push_back({i,j,dist});
            }
        }

        sort(begin(edges),end(edges),[](auto &edge1,auto &edge2){
            return edge1[2]<edge2[2];
        });

        int cost = 0;
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(find(u)==find(v))
            {
                continue;
            }else{
                cost += wt;
                Union(u,v);
            }
        }

        return cost;
        
    }
};
