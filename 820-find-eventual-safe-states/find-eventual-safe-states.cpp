class Solution {
public:

    bool findSafeNodes(vector<vector<int>>& graph, vector<int>& safe, int node) {
        if (graph[node].empty()) return true;
        if (safe[node] == 1) return true;
        if (safe[node] == 0) return false;
        if (safe[node] == 2) return false; // we are currently visiting this node ie it's int he recursion stack.

        safe[node] = 2; // mark this as visiting 

        bool isSafe = true;
        for (int n : graph[node]) {
            if (!findSafeNodes(graph, safe, n)) {
                isSafe = false;
            }
        }
        safe[node] = isSafe; // we have finished visiting this node and know if it's safe or not.
        return isSafe;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safe(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (safe[i] == -1 ) {
                findSafeNodes(graph, safe, i);
            }
        }
        vector<int> ans;
        for (int i = 0; i < safe.size(); i++) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};