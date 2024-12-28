int findMin(int* a, int n) {
    int left=0, right=n-1;
    if(a[0] < a[right])
        return a[0];
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid] > a[n-1])
            left=mid+1;
        else right=mid-1;
    }
    return a[left];
}