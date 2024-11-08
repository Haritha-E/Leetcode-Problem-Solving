void moveZeroes(int* nums, int numsSize) {
    int n = 0;
    for(int i = 0; i<numsSize; i++){
        if(nums[i] != 0){
            int temp = nums[n];
            nums[n] = nums[i];
            nums[i] = temp;
            n++;
        }
    }
}