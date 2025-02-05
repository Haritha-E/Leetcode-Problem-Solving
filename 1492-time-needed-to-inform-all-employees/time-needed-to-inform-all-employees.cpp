class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> vis (n,0);
        int ans = 0;
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            if(manager[i] == -1) continue;
            mp[manager[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty())
        {
            int head = q.front().first;
            int time = q.front().second;
            q.pop();
            ans = max(ans, time);
            if(vis[head] == 0)
            {
                vis[head] = 1;
                for(auto c:mp[head]) q.push({c,time+informTime[head]});
            }
        }
        return ans;
    }
};