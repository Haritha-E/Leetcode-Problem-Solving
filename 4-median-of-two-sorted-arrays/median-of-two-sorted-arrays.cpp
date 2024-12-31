class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i=0;i<nums1.size();i++)
            res.push_back(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            res.push_back(nums2[i]);
        sort(res.begin(),res.end());
        int l=0,r=res.size()-1;
        double m=(l+r)/2;
        if(res.size()%2!=0)
            return res[m];
        else
            return (res[m]+res[m+1])/2.0;
    }
};