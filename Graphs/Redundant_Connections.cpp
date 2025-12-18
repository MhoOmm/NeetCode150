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

        return parent[i] = find(parent[i]);
    }

    void nion(int x ,int y){
        int parx = find(x);
        int pary = find(y);
        if(parx==pary)
        {
            return;
        }

        if(rank[pary]>rank[parx])
        {
            parent[parx] = pary;
        }
        else if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }
        else{
            parent[pary] = parx;
            rank[parx]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n  = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for(int i =0;i<n;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            if(find(u)==find(v))
            {
                return {u,v};
            }else{
                nion(u,v);
            }
        }

        return edges[n-1];
        
    }
};
