class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i)
    {
        if(i == parent[i])
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void Union(int x,int y)
    {
        int parx = find(x);
        int pary = find(y);
        if(parx==pary)
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
        else{
            parent[parx] = pary;
            rank[pary]++;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        vector<vector<int>>adj(n);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            Union(u,v);
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                count++;
            }

        }

        return count;

    }
};
