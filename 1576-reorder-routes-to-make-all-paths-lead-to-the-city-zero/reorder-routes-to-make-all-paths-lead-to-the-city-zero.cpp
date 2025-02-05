class Solution {
public:
    int dfs(int node ,vector<int>& vis , unordered_map<int, vector<pair<int, int>>>& adj)
    {
        vis[node]= 1;
        int counter =0;
        for(auto it : adj[node])
        {
            int to_dir = it.first;
            int from_dir = it.second;
            if(!vis[to_dir]){
                if(from_dir){
                    counter+=1;
                }
                counter += dfs(to_dir ,vis,adj);
            }
        }
        return counter;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>vis(n,0);
        for(auto x : connections)
        {
            adj[x[0]].push_back({x[1],1});
            adj[x[1]].push_back({x[0],0});
        }

        return dfs(0,vis,adj);
        
    }
};