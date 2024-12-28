class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        vector<int>v;
        int left=0, right=a.size()-1;
        while(left < right){
            int sum=a[left] + a[right];
            if(sum == t)
                return{left+1, right+1};
            else if(sum<t)
                left++;
            else
                right--;
        }
        return {-1,-1};
    }
};