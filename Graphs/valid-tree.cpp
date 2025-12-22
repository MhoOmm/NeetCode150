// optimal - only dfs and check the visited array to check whether one component
class Solution {
public:
    bool isCycle(int node,int par,vector<vector<int>>&adj,vector<bool>&visited)
    {
        visited[node] = true;
        for(auto &neig:adj[node])
        {
            if(!visited[neig])
            {
                if(isCycle(neig,node,adj,visited))
                {
                    return true;
                }
            }
            else if(neig != par){
                return true;
            }
        }
        return false;
    }  
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        if(isCycle(0,-1,adj,visited))
        {
            return false;
        }

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }

        return true;
    }
};



// brute force - Use DSU to check if one component and dfs to check cycle
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

    bool isCycle(int node,int par,vector<vector<int>>&adj,vector<bool>&visited)
    {
        visited[node] = true;
        for(auto &neig:adj[node])
        {
            if(!visited[neig])
            {
                if(isCycle(neig,node,adj,visited))
                {
                    return true;
                }
            }
            else if(neig != par){
                return true;
            }
        }
        return false;
    }  
    bool validTree(int n, vector<vector<int>>& edges) {

        int count = 0;
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] =0;
        }
        vector<vector<int>>adj(n);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            Union(u,v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i){
                count++;
            }
        }

        vector<bool>visited(n,false);
        if(isCycle(0,-1,adj,visited)  || count>1)
        {
            return false;
        }

        return true;
    }
};

