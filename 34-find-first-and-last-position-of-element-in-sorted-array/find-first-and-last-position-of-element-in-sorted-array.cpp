class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1, firstOcc = 0, lastOcc = 0;
        while(left <= right)
        {
          int mid =(left + right) / 2;
          if(nums[mid] == target)
          {
            if( left == mid ||nums[mid -1] != target)
            {
              firstOcc = mid;
              break;
            }
            right = mid - 1;
          }
          else if(nums[mid] < target) left = mid + 1;
          else right = mid - 1;
        }
        if(left > right) return {-1, -1};
        left = 0, right = nums.size() - 1;
        while(left <= right)
        {
          int mid =(left + right) / 2;
          if(nums[mid] == target)
          {
            if( right == mid ||nums[mid +  1] != target)
            {
              lastOcc = mid;
              break;
            }
            left  = mid + 1;
          }
          else if(nums[mid] < target) left = mid + 1;
          else right = mid - 1;
        }
        return {firstOcc, lastOcc};

    }
};