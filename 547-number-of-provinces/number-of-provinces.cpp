class Solution {
public:
    int find(int node, vector<int>& par){
        if(par[node]==node) return node;
        return par[node]=find(par[node], par);
    }
    void unionset(int u, int v, vector<int>& par, vector<int>& sz){
        int pu=find(u, par);
        int pv=find(v, par);
        if(pu==pv) return;
        if(sz[pu]<sz[pv]){
            par[pu]=pv;
            sz[pv]+=sz[pu];
        }
        else{
            par[pv]=pu;
            sz[pu]+=sz[pv];
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> par(n);
        iota(par.begin(), par.end(), 0);
        vector<vector<int>> edges;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(i!=j && isConnected[i][j]==1) edges.push_back({i, j});
            }
        }
        vector<int> sz(n, 0);
        for( auto ed:edges) unionset(ed[0], ed[1], par, sz);
        int ans=0;
        for(int i=0; i<n; i++) if(par[i]==i) ans++;
        return ans;

    }
};