class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int p1=cost[0];
        int p2=cost[1];
        int c=0;
        for(int i=2;i<n;i++){
            c=cost[i]+min(p2,p1);
            p1=p2;
            p2=c;
        }
        return min(p1,p2);
    }
};